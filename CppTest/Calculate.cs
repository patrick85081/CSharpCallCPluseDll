using System;
using System.Runtime.InteropServices;

namespace CppTest
{
    public class Calculate : IDisposable
    {
        //傳入和傳出的型態格式必須同ForExternCall.cpp內的設置！！

        [DllImport("TestDll", EntryPoint = "CreateInstance")]
        private static extern IntPtr CreateInstance();

        [DllImport("TestDll", EntryPoint = "DisposeInstance")]
        private static extern void DisposeInstance(IntPtr instance);

        //我將dll檔放到D:，然後設置進入點
        [DllImport("TestDll.dll", EntryPoint = "Add")]
        private static extern int Add(IntPtr instance, int a, int b);

        //也可以不設置進入點，但函數名稱必須相同
        [DllImport("TestDll.dll", EntryPoint ="Sub")]
        private static extern int Sub(IntPtr instance, int a, int b);

        [DllImport("TestDll", EntryPoint = "Multi")]
        private static extern int Mul(IntPtr instance, int a, int b);

        [DllImport("TestDll", EntryPoint = "Div")]
        private static extern float Div(IntPtr instance, int a, int b);

        [DllImport("TestDll", EntryPoint = "RegisterCallback")]
        private static extern void RegisterCallback(IntPtr instance, Callback callback);


        public delegate void Callback(int a, int b, int c, int d);

        IntPtr instance = IntPtr.Zero;

        public Calculate()
        {
            instance = CreateInstance();
        }

        public int Add(int a, int b)
        {
            return Add(instance, a, b);
        }

        public int Sub(int a, int b)
        {
            return Sub(instance, a, b);
        }

        public int Mul(int a, int b)
        {
            return Mul(instance, a, b);
        }

        public float Div(int a, int b)
        {
            return Div(instance, a, b);
        }

        public void RegisterCallback(Callback callback)
        {
            RegisterCallback(instance, callback);
        }

        protected virtual void Dispose(bool bDisposing)
        {
            if (this.instance != IntPtr.Zero)
            {
                // Call the DLL Export to dispose this class
                DisposeInstance(this.instance);
                this.instance = IntPtr.Zero;
            }

            if (bDisposing)
            {
                // No need to call the finalizer since we've now cleaned
                // up the unmanaged memory
                GC.SuppressFinalize(this);
            }
        }

        public void Dispose()
        {
            Dispose(true);
        }

        ~Calculate()
        {
            Dispose(false);
        }
    }
}
