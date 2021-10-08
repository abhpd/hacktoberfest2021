using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Windows.Forms;
using EASendMail;

namespace Presentacion
{
    public class Emailer
    {
        public void SendEmail(string mesage)
        {
            try
            {
                SmtpMail mail = new SmtpMail("TryIt");
                
                mail.From = "example@mail.com";
                mail.To = "example@mail.com";
                mail.Subject = "Subject";
                mail.TextBody = mesage;

                //Smtp for Gmail, change in case of require
                SmtpServer server = new SmtpServer("smtp.gmail.com");

                server.User = "mailUser@mail.com";
                server.Password = "password";
                server.Port = 587;
                server.ConnectType = SmtpConnectType.ConnectSSLAuto;

                SmtpClient client = new SmtpClient();

                client.SendMail(server, mail);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error al enviar el correo. " + ex.Message);
            }
        }
    }
}
