#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string m_ideas[100];

	public:
		Brain();
    	Brain(const Brain &copy);
    	Brain &operator=(const Brain &other);
    	virtual ~Brain();

		std::string &getIdea(int index);
		void setIdea(int index, std::string idea);

};

#endif
