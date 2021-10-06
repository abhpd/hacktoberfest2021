using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using PracticeMVC.Models;
using PracticeMVC.ViewModels;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;

namespace PracticeMVC.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly IStudentRepository _studentRepository;


        //
        public HomeController(ILogger<HomeController> logger, IStudentRepository studentRepository) //Constructor injection
        {
            //IStudentRepository studentRepository1 = new IStudentRepository(); //Tight Coupling
            _logger = logger;
            _studentRepository = studentRepository;
        }        
       
        
        public IActionResult Index() //Action ko name ra view ko name same huna parxa
        {
            var model = _studentRepository.GetAllStudents();
            return View(model);            

        }


        [HttpGet]        

        public IActionResult Create()
        {
            return View();
        }

        [HttpPost]
        //IActionResult
        //ActionResult
        //ViewResult
        //JsonResult
        public IActionResult Create(StudentCreateViewModel model)
        {
            if (ModelState.IsValid)
            {
                Student newStudent = new Student
                {
                    Name=model.Name,
                    Address=model.Address,
                    Faculty = model.Faculty
                };
                _studentRepository.Add(newStudent);
                return RedirectToAction("index", new { id = newStudent.Id });

            }

            return View();
           
        }

        [HttpGet]
        public IActionResult Edit(int id)
        {
            Student student = _studentRepository.GetStudentById(id);
            StudentEditViewModel studentEditViewModel = new StudentEditViewModel
            {
                Id = student.Id,
                Name = student.Name,
                Address = student.Address,
                Faculty = student.Faculty
            };

            return View(studentEditViewModel);
        }

        [HttpPost]
        public IActionResult Edit(StudentEditViewModel model)
        {
            if (ModelState.IsValid)
            {
                Student student = _studentRepository.GetStudentById(model.Id);
                student.Name = model.Name; //Model ko name vaneko hamle form ma vhareko name
                student.Address = model.Address;
                student.Faculty = model.Faculty;
                _studentRepository.Update(student);
                return RedirectToAction("index");                          
            }

            return View();
        }



        [HttpGet]
        public IActionResult Delete(int id)
        {
            Student student = _studentRepository.GetStudentById(id);
            StudentDeleteViewModel studentDeleteViewModel = new StudentDeleteViewModel
            {
                Id = student.Id,
                Name = student.Name,
                Address = student.Address,
                Faculty = student.Faculty
            };

            return View(studentDeleteViewModel);
        }

        [HttpPost]
        public IActionResult Delete(StudentEditViewModel model)
        {
            if (model !=null)
            {
                Student student = _studentRepository.GetStudentById(model.Id);
                _studentRepository.Delete(student.Id);
                return RedirectToAction("index");
            }

            return View();
        }





        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
