#include<stdio.h>
#include<json-c/json.h>

int main()
{
	json_object* json_obj = json_object_new_object(); ////生成{ }
	json_object_object_add(json_obj, "name", json_object_new_string("xxx")); //{"name:xxx"}
	json_object_object_add(json_obj, "age", json_object_new_string("28")); //{"name":"xxx", "age":"28"}
	json_object_object_add(json_obj, "city", json_object_new_string("shanghai"));
	printf("get string:%s\n", json_object_get_string(json_obj));


	json_object* my_arry = json_object_new_array();

	json_object_array_add(my_arry, json_object_new_int(1));
	json_object_array_add(my_arry, json_object_new_int(2));
	json_object_array_add(my_arry, json_object_new_int(3));
	json_object_array_add(my_arry, json_object_new_int(4));
	printf("my_arry:\n\t%s \n",json_object_to_json_string(my_arry) );

	json_object_object_add(json_obj, "test", my_arry);
	printf("get string:%s\n", json_object_get_string(json_obj));


	json_object* jsonObj = json_tokener_parse(json_object_get_string(json_obj));
	printf("get string:%s\n", json_object_to_json_string(jsonObj));
	if (jsonObj != NULL) {
		json_object_object_foreach(jsonObj, key, value) { // //遍历对象
			printf("\tkey:%s, vaule:%s \n", key, json_object_to_json_string(value));
		}
		json_object_put(jsonObj);/*释放资源*/
	}


	json_object_put(json_obj);/*释放资源*/
	return 0;
}
