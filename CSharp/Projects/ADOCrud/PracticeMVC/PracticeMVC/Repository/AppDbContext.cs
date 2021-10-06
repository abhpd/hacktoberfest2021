using Microsoft.EntityFrameworkCore;
using PracticeMVC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PracticeMVC.Repository
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) //Dbcontext ko instance
            :base(options) //Pass options to base DbContext
        {
                
        }
        public DbSet<Student> Students { get; set; }
        //DB entity set for each type. Use this property Students to query and save instances of the student class
        
    }
}
