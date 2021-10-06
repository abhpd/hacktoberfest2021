using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PracticeMVC.Utility
{
    public class ConnectionString
    {
        //Change your connection string with your database name.In my case here is practiceStudent
        private static string connectionString = "Data Source=DESKTOP-KBAPQC1;Initial Catalog=PracticeStudent;Integrated Security=True;";

        public static string conString { get => connectionString; }
    }
}
