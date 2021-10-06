using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Threading.Tasks;

namespace AdoCrud.Models
{
    public class ApplicationDb
    {
        private readonly IConfiguration _config;


        public ApplicationDb(IConfiguration configuration)
        {
            _config = configuration;
        }

        static string conString = null;
        public string GetConString()
        {
            conString = _config.GetConnectionString("TestConnection").ToString();
            return conString;
        }

        //static string conString = @"Data Source=DESKTOP-KBAPQC1;Initial Catalog=DonationDB;Integrated Security=True";
        SqlConnection con = new SqlConnection(conString);

        public DataSet CandidateGet(Candidate can, out string msg)
        {
            DataSet ds = new DataSet();
            msg = "";
            try
            {
                SqlCommand com = new SqlCommand("spCandidate", con);
                com.CommandType = CommandType.StoredProcedure;

                com.Parameters.AddWithValue("@Id", can.Id);
                com.Parameters.AddWithValue("@FullName", can.FullName);
                com.Parameters.AddWithValue("@Mobile", can.Mobile);
                com.Parameters.AddWithValue("@Email", can.Email);
                com.Parameters.AddWithValue("@Age", can.Age);
                com.Parameters.AddWithValue("@BloodGroup", can.BloodGroup);
                com.Parameters.AddWithValue("@Address", can.Address);
                com.Parameters.AddWithValue("@Flag", can.Flag);
                SqlDataAdapter da = new SqlDataAdapter(com);
                da.Fill(ds);
                return ds;
            }
            catch (Exception ex)
            {

                msg = ex.Message;
                return ds;                
            }
            

        }

    }
}
