using PracticeMVC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PracticeMVC
{
    public interface IStudentRepository
    {
        Student GetStudentById(int Id);
        IEnumerable<Student> GetAllStudents();
        Student Add(Student student);
        Student Update(Student studentChanges);
        Student Delete(int id);

    }
}
