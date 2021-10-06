using PracticeMVC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PracticeMVC.Repository
{
    public class StudentSQLRepository : IStudentRepository
    {
        private readonly AppDbContext _context;

        public StudentSQLRepository(AppDbContext context)
        {
            _context = context;
        }

        public Student Add(Student student)
        {
            _context.Students.Add(student);
            _context.SaveChanges();
            return student;
        }

        public Student Delete(int id)
        {
            Student student = _context.Students.Find(id);
            if(student != null)
            {
                _context.Students.Remove(student);
                _context.SaveChanges();
            }

            return student;
        }

        public IEnumerable<Student> GetAllStudents()
        {
            return _context.Students;
        }

        public Student GetStudentById(int Id)
        {
            return _context.Students.Find(Id);
        }

        public Student Update(Student studentChanges)
        {
            var student = _context.Students.Attach(studentChanges);
            student.State = Microsoft.EntityFrameworkCore.EntityState.Modified;
            _context.SaveChanges();
            return studentChanges;
        }
    }
}
