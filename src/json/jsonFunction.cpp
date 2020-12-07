#include "jsonFunction.h"
#include <iostream>
#include <fstream>


Json::Value readFile(std::string JsonFileName)
{
    
    std::ifstream ifs(JsonFileName.c_str(), std::ios::binary);
        
    if(!ifs)
	{
		std::cout << "Unable to open " << JsonFileName << " for reading.\n";
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
    //std::cout << root << std::endl;
    return root;
}

Json::Value readString(std::string StringName)
{

    const std::string rawJson = R"({"Age": 20, "Name": "colin"})";
    const auto rawJsonLength = static_cast<int>(rawJson.length());
    constexpr bool shouldUseOldWay = false;
    JSONCPP_STRING err;
    Json::Value root;

    if (shouldUseOldWay) {
        Json::Reader reader;
        reader.parse(rawJson, root);
    } else {
        Json::CharReaderBuilder builder;
        const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
        if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &root,
                        &err)) {
        std::cout << "error" << std::endl;
        return EXIT_FAILURE;
        }
    }

    return root;
}

int writeFile(std::string FileName)
{
    Json::Value root;
    Json::StreamWriterBuilder builder;
    const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    root["Name"] = "robin";
    root["Age"] = 20;
    writer->write(root, &std::cout);

    std::ofstream ofs(FileName.c_str(), std::ios::out);
    
    ofs << root << std::endl;
    ofs.flush();
    ofs.close();


    return EXIT_SUCCESS;
}

int writeString(std::string StringName)
{
    Json::Value root;
    Json::Value data;
    constexpr bool shouldUseOldWay = false;
    root["action"] = "run";
    data["number"] = 1;
    root["data"] = data;

    if (shouldUseOldWay) {
        Json::FastWriter writer;
        const std::string json_file = writer.write(root);
        std::cout << json_file << std::endl;
    } else {
        Json::StreamWriterBuilder builder;
        const std::string json_file = Json::writeString(builder, root);
        std::cout << json_file << std::endl;
    }

    return EXIT_SUCCESS;
}



