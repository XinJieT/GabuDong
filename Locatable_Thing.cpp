
#include "Locatable_Thing.h"

Locatable_Thing::Locatable_Thing
(GPS_DD arg_gps)
{
  this->location = arg_gps;
}

Json::Value *
Locatable_Thing::dump2JSON
()
{
  Json::Value * result_ptr = this->Thing::dump2JSON();
  Json::Value * jv_ptr = NULL;

  if (result_ptr != NULL)
    {
      printf("Thing dump2JSON from Core --\n");
      std::cout << (*result_ptr) << std::endl;
    }
  else
    {
      result_ptr = new Json::Value ();
    }

  (*result_ptr)["location"] = (*((this->location).dump2JSON()));

  return result_ptr;
}

void
Locatable_Thing::JSON2Object
(Json::Value * arg_json_ptr)
{
  Exception_Info * ei_ptr = NULL;
  
  ee1520_Exception lv_exception {};
  ee1520_Exception * lv_exception_ptr = &lv_exception;

  JSON2Object_precheck(arg_json_ptr, lv_exception_ptr,
		       EE1520_ERROR_JSON2OBJECT_THING);
  
  try
    {
      this->Thing::JSON2Object(arg_json_ptr);
    }
  catch(ee1520_Exception e)
    {
      JSON2Object_appendEI(e, lv_exception_ptr, 0);
    }
  
  // "url"
  if (((*arg_json_ptr)["location"].isNull() == true) ||
      ((*arg_json_ptr)["location"].isObject() == false))
    {
      ei_ptr = new Exception_Info {};
      ei_ptr->where_code = EE1520_ERROR_JSON2OBJECT_THING;
      ei_ptr->which_string = "location";
      ei_ptr->how_code = EE1520_ERROR_NORMAL;

      if ((*arg_json_ptr)["location"].isNull() == true)
	{
	  ei_ptr->what_code = EE1520_ERROR_JSON_KEY_MISSING;
	}
      else
	{
	  ei_ptr->what_code = EE1520_ERROR_JSON_KEY_TYPE_MISMATCHED;
	}

      ei_ptr->array_index = 0;
      
      (lv_exception_ptr->info_vector).push_back(ei_ptr);
    }
  else
    {
      // later
      // this->url = ((*arg_json_ptr)["location"]).asString();
    }

  if ((lv_exception_ptr->info_vector).size() != 0)
    {
      throw (*lv_exception_ptr);
    }

  return;
}

