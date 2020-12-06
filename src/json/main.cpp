#include "json.h"
#include <iostream>
#include <fstream>
#include <iostream>


using namespace std;

int main()
{
        std::string fileName = "/home/yh/alex/src/config/dbconfig";
        ifstream ifs(fileName,ios::binary);
        
        if(!ifs)
	{
		cout << "Unable to open " << fileName << " for reading.\n";
		return (1);
	}
    
        Json::Value root;

        Json::CharReaderBuilder builder;
        builder["collectComments"] = true;
        JSONCPP_STRING errs;
        if (!parseFromStream(builder, ifs, &root, &errs)) {
                std::cout << errs << std::endl;
                return EXIT_FAILURE;
        }
        std::cout << root << std::endl;


        return 0;

}
