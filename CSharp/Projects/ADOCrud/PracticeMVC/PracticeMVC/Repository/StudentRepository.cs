using PracticeMVC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PracticeMVC.Repository
{
    public class StudentRepository : IStudentRepository
    {
        private List<Student> _studentList;

        public StudentRepository()
        {
            _studentList = new List<Student>()
            {
                new Student(){Id=101, Name="Bipin Bhattarai", Address="Kritipur", Faculty="BBS"},
                new Student(){Id=102, Name="Manish Bhattarai", Address="Kritipur", Faculty="BBA"},
                new Student(){Id=103, Name="Bipana Thapa", Address="Kritipur", Faculty="BSW"},
                new Student(){Id=104, Name="Suraj Basnet", Address="Lalitpur", Faculty="CSIT"},
                new Student(){Id=105, Name="Sujan Bhattarai", Address="Kritipur", Faculty="BCA"}
            };
        }

        //Create
        public Student Add(Student student)
        {
            student.Id = _studentList.Max(s => s.Id) + 1;
            _studentList.Add(student);
            return student;
        }

        //Delete
        public Student Delete(int id)
        {
            Student student = _studentList.FirstOrDefault(s => s.Id == id);
            if (student != null)
            {
                _studentList.Remove(student);
            }
            return student;
        }

        //Read
        public IEnumerable<Student> GetAllStudents()
        {
            return _studentList;
        }

        public Student GetStudentById(int Id)
        {
            return _studentList.FirstOrDefault(s=> s.Id == Id);
        }

        public Student Update(Student studentChanges)
        {
            Student student = _studentList.FirstOrDefault(s => s.Id == studentChanges.Id);
            if(student!= null)
            {
                student.Name = studentChanges.Name;
                student.Address = studentChanges.Address;
                student.Faculty = studentChanges.Faculty;
            }
            return student;
        }
    }
}
