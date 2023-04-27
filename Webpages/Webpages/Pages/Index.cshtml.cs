using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.ComponentModel.DataAnnotations;
using System.Runtime.Intrinsics.Arm;
using System.Security.Cryptography;
using System.Text;
using System.Xml.Linq;

namespace SWEProject.Pages
{
     /// <summary>
     /// Login Page. Currently doesn't link up to the desktop app,
     /// only authenticates one username/password.
     /// </summary>
    public class IndexModel : PageModel
    {
        private readonly ILogger<IndexModel> _logger;

        public string hash = "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8";
        public string username = "user";
        /// <summary>
        /// Username
        /// </summary>
        [Required]
        [BindProperty]
        [Display(Name = "Username")]
        public string Username { get; set; }

        /// <summary>  
        /// Password.
        /// </summary>  
        [Required]
        [BindProperty, DataType(DataType.Password)]
        [Display(Name = "Password")]
        public string Password { get; set; }

        public IndexModel(ILogger<IndexModel> logger)
        {
            _logger = logger;
        }

        public void OnGet()
        {

        }

        public IActionResult OnPostLogIn()
        {
            if (Username == null || Password == null) return Page();
            if (Username.Equals(username) && VerifyPassword())
            {
                return RedirectToPage("/Recipe");
            }

            //credentials did not match, try again
            return Page();
        }

        private bool VerifyPassword()
        {
            string hashedInput = Convert.ToHexString(SHA1.HashData(Encoding.UTF8.GetBytes(Password))).ToLower();
            if (hashedInput.Equals(hash))
            {
                return true;
            }
            else return false;  
        }
    }
}