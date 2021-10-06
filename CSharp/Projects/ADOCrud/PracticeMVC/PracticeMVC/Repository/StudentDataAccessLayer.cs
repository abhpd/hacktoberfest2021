using Microsoft.Data.SqlClient;
using PracticeMVC.Models;
using PracticeMVC.Utility;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PracticeMVC.Repository
{
    public class StudentDataAccessLayer : IStudentRepository
    {
        string connectionString = ConnectionString.conString;

        public Student Add(Student student)
        {
            using(SqlConnection con = new SqlConnection(connectionString))
            {
                //string query = @"Insert Into Students (Name, Address, Faculty) Values(@Name, @Address, @Faculty);";
                

                SqlCommand cmd = new SqlCommand("spAddStudent", con);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;

                //cmd.Parameters.AddWithValue("@Id", student.Id);
                cmd.Parameters.AddWithValue("@Name", student.Name);
                cmd.Parameters.AddWithValue("@Address", student.Address);
                cmd.Parameters.AddWithValue("@Faculty", student.Faculty);

                con.Open(); //THis is related to connection class
                cmd.ExecuteNonQuery();//This is related to command class
                con.Close();

            }

            return student;
        }

        public Student Delete(int id)
        {
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                string query = @"Delete Students where Id = @Id;";

                SqlCommand cmd = new SqlCommand(query, con);

                cmd.Parameters.AddWithValue("@Id", id);               

                con.Open(); //THis is related to connection class
                cmd.ExecuteNonQuery();//This is related to command class
                con.Close();

            }

            return null;
        }

        public IEnumerable<Student> GetAllStudents()
        {
            List<Student> listStudent = new List<Student>();
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                string query = @"Select * From Students;";

                SqlCommand cmd = new SqlCommand(query, con);
                

                con.Open(); //THis is related to connection class

                SqlDataReader sqlDataReader = cmd.ExecuteReader();

                while (sqlDataReader.Read())
                {
                    Student student = new Student();
                    student.Id = Convert.ToInt32(sqlDataReader["Id"]);
                    student.Name = sqlDataReader["Name"].ToString();
                    student.Address = sqlDataReader["Address"].ToString();
                    student.Faculty = sqlDataReader["Faculty"].ToString();

                    listStudent.Add(student);
                    
                }
                con.Close();

            }

            return listStudent;
        }

        public Student GetStudentById(int Id)
        {
            Student student = new Student();

            using (SqlConnection con = new SqlConnection(connectionString))
            {
                string query = @"Select * From Students where Id= @Id;";

                SqlCommand cmd = new SqlCommand(query, con);
                cmd.Parameters.AddWithValue("@Id", Id);

                con.Open(); //THis is related to connection class

                SqlDataReader sqlDataReader = cmd.ExecuteReader();

                while (sqlDataReader.Read())
                {
                    
                    student.Id = Convert.ToInt32(sqlDataReader["Id"]);
                    student.Name = sqlDataReader["Name"].ToString();
                    student.Address = sqlDataReader["Address"].ToString();
                    student.Faculty = sqlDataReader["Faculty"].ToString();                  

                }
                con.Close();

            }

            return student;
        }

        public Student Update(Student studentChanges)
        {
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                //string query = @"Insert Into Students (Name, Address, Faculty) Values(@Name, @Address, @Faculty);";
                string query = @"Update Students SET Name = @Name , Address =@Address , Faculty =@Faculty Where Id= @Id;";

                SqlCommand cmd = new SqlCommand(query, con);

                cmd.Parameters.AddWithValue("@Id", studentChanges.Id);
                cmd.Parameters.AddWithValue("@Name", studentChanges.Name);
                cmd.Parameters.AddWithValue("@Address", studentChanges.Address);
                cmd.Parameters.AddWithValue("@Faculty", studentChanges.Faculty);

                con.Open(); //THis is related to connection class
                cmd.ExecuteNonQuery();//This is related to command class
                con.Close();

            }

            return studentChanges;
        }
    }
}
