#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<json/json.h>

int main()
{
	const char* str = 
		      "{\"praenomen\":\"Gaius\",\"nomen\":\"Julius\",\"cognomen\":\"Caezar\","
			        "\"born\":-100,\"died\":-44}";
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(str, root))
	{
		if (!root["praenomen"].isNull()) {
			std::string str = root["praenomen"].asString();
			printf("str = [%s]\n", str.c_str());
		}
	}
	else {
		printf("parse failed \n");
	}
	return 0;
}

