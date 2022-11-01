//hospital.h
#ifndef HOSPITAL_H_
#define HOSPITAL_H_

#include "entity.h"
#include <picojson.h>


class Hospital: public Entity 
{
	public:
		 Hospital();
		Hospital(picojson::object EntityData);
		~Hospital();
		virtual std::string getType();


};

#endif
