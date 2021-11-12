#include <mailio/message.hpp>
#include <mailio/mime.hpp>
#include <mailio/smtp.hpp>

using mailio::message;
using mailio::mail_address;
using mailio::mime;
using mailio::smtp;
using mailio::smtp_server;
using mailio::stmp_error;
using mailio::dialog_error;

#define max_sz 100

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "_smtp.cc"

class SMTP{
    protected:
        const int def_min_sz = 0;
        const int def_max_sz = max_sz;
        const string ConsoleHDR = "SMTP";

        vector<string> recept_ls(def_max_sz) = { "undefined" };
        bool vect_lock = true;
        //info -> email
        string from = "local";
        string sender = "local@me.com";
        string plain_pwn = "Блядь";
        //email header
        email_message msg;
        msg.header_codec(message::header_codec_t::BASE64);
        msg.from(mail_address(from, sender));

    private:
        vector<auto> context_ln[max_sz] = {
            "волшебная текстовая строка"
            };
        int itel = 0;

        auto* msgu8;

    public:
        SMTP(vector<string> adresses, titled) 
        : maiL_list(adresses), header(titled) {

            cout << "[SERVER-TEST] -- BASELINE" << endl;
            if(baseline_test() == 0)
                cout << "[SERVER-TEST] -- SUCCESS" << endl;
            else
                cout << "[SERVER-TEST -- FAIL" << endl;

        }

        bool open_vectlock();

        bool add_vect_recepient(address);
        bool add_address(int id, string address);//by vector location
        bool add_address(string address); //last from que

        int addln_context(auto ln);
        int craft_context(string subject);

        int baseline_test(){
            
            try{
                add_address("local@local.com"); //fix that for proper

            const string cells[5] = {
                "И кроваво-черное ничто начало вращаться\n",
                "система клеток, связанных внутри, клеток\n",
                "связанных внутри клеток,\n",
                "связанных между собой, внутри одного ствола\n",
                "И ужасно отчетливо на фоне темноты играл высокий белый фонтан.\n"
            }
            for(int i = 0; i < 5 ; i++)
                addln_context(cells[i]);

            craft_context("within cells interlinked\n");

            const char* msgs =
            #if defined(__cpp_char8_t)
                reinterpret_cast<const char *>(msgu8);
            #else
                msgu8;
            #endif
            msg.content(msgs);

            // use a server with plain (non-SSL) connectivity
            smtp connect("smtp.mailserver.com", 587);
            // modify username/password to use real credentials
            connect.authenticate(sender, plain_pwn, smtp::auth_method_t::LOGIN);
            connect.submit(msg);
            }
            catch (smtp_error& exc)
            {
                cout << exc.what() << endl;
                return -1;
            }
            catch (dialog_error& exc)
            {
                cout << exc.what() << endl;
                return -2;
            }

            return EXIT_SUCCESS;
        }
};