#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        Zombie(Zombie &other);
        ~Zombie();
        void    announce();
};

#endif
