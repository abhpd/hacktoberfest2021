using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;// -> Model Validation
using System.Linq;
using System.Threading.Tasks;

namespace PracticeMVC.ViewModels //DTO(Data Transfer Object) //If model doesn't have additional data display to users
{
    public class StudentCreateViewModel
    {
        public int Id { get; set; }

        [Required]
        [MaxLength(200)]
        public string Name { get; set; }
        [Required]
        public string Address { get; set; }
        [Required]
        public string Faculty { get; set; }        

    }
}
