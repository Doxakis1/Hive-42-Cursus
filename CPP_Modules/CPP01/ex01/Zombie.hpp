#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        Zombie(Zombie &other);
        ~Zombie();

        void    changeName(std::string name);
        void    announce();

};

#endif
