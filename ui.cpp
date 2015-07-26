#include <iostream>
#include <curl/curl.h>

using namespace std;

class Interface{
	bool quit;
	int choice;

	void create(){
	cout << "Enter userN: ";
		string userN;
		cin >> userN;
		
		cout << "Enter passH: ";
		string passH;
		cin >> passH;
		
		string urlQuery = "http://localhost/create?" + userN 
			+ "+" + passH + "+";
			
		cout << "urlQuery: " << urlQuery << endl;
	
		CURL *curl;
		CURLcode res;
		
		curl_global_init(CURL_GLOBAL_ALL);
		curl = curl_easy_init();
		
		if(curl){
			curl_easy_setopt(curl, CURLOPT_URL, urlQuery.c_str());
			res = curl_easy_perform(curl);
			
			if(res != CURLE_OK){
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			}
			//cout << CURLE_OK << " here: " << res << endl;
			
			curl_easy_cleanup(curl);
		}
		curl_global_cleanup();
	}
	
	void login(){
	cout << "Enter userN: ";
		string userN;
		cin >> userN;
		
		cout << "Enter passH: ";
		string passH;
		cin >> passH;
		
		string urlQuery = "http://localhost/login?" + userN 
			+ "+" + passH + "+";
			
		cout << "urlQuery: " << urlQuery << endl;
	
		CURL *curl;
		CURLcode res;
		
		curl_global_init(CURL_GLOBAL_ALL);
		curl = curl_easy_init();
		
		if(curl){
			curl_easy_setopt(curl, CURLOPT_URL, urlQuery.c_str());
			res = curl_easy_perform(curl);
			
			if(res != CURLE_OK){
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			}
			//cout << CURLE_OK << " here: " << res << endl;
			
			curl_easy_cleanup(curl);
		}
		curl_global_cleanup();
	}
	
  public:
  
	Interface(){
		quit = false;
		
		while(quit == false){
			cout << "\n\nSelect operation: " << endl;
			cout << "\t(1) Create Acc" << endl;
			cout << "\t(2) Login" << endl;
			cout << "\t(*) Quit" << endl;
			
			cin >> choice;
			
			if(choice == 1)
				create();
			else if(choice == 2)
				login();
			else
				quit = true;
		}
	}

};


int main(){
	
	Interface start;

	return 0;
}
