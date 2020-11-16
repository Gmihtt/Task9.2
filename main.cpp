#include <iostream>

class Armor {
public:
    Armor() : num(0) {}
    Armor(int num) : num(num) {
        std::cout << "Armor; count: " << num << std::endl;
    }

    int num;
};

class Knife {
public:
    Knife() : num(0) {}
    Knife(int num) : num(num) {
        std::cout << "Knife; count: " << num << std::endl;
    }

    int num;
};

class Pistol {
public:
    Pistol() : num(0) {}
    Pistol(int num) : num(num) {
        std::cout << "Pistol; count: " << num << std::endl;
    }

    int num;
};

class Gun {
public:
    Gun() : num(0) {}
    Gun(int num) : num(num) {
        std::cout << "Gun; count: " << num << std::endl;
    }

    int num;
};

class Grenade {
public:
    Grenade() : num(0) {}
    Grenade(int num) : num(num) {
        std::cout << "Grenade; count: " << num << std::endl;
    }

    int num;
};

class SappersKit {
public:
    SappersKit() : num(0) {}
    SappersKit(int num) : num(num) {
        std::cout << "SappersKit; count: " << num << std::endl;
    }

    int num;
};

class Bomb {
public:
    Bomb() : num(0) {}
    Bomb(int num) : num(num) {
        std::cout << "Bomb; count: " << num << std::endl;
    }

    int num;
};

class Person {
public:
    Person() = default;
    Armor armor = Armor();
    Knife knife = Knife();
    Pistol pistol = Pistol();
    Gun gun = Gun();
    Grenade grenade = Grenade();
    SappersKit sappersKit = SappersKit();
    Bomb bomb = Bomb();
};

class Builder {
public:
    Builder() = default;

    Builder &buildArmor(Armor armor) {
        armor_ = armor;
        return *this;
    }

    Builder &buildKnife(Knife knife) {
        knife_ = knife;
        return *this;
    }

    Builder &buildPistol(Pistol pistol) {
        pistol_ = pistol;
        return *this;
    }

    Builder &buildGun(Gun gun) {
        gun_ = gun;
        return *this;
    }

    Builder &buildGrenade(Grenade grenade) {
        grenade_ = grenade;
        return *this;
    }

    Builder &buildSappersKit(SappersKit sappersKit) {
        sappersKit_ = sappersKit;
        return *this;
    }

    Builder &buildBomb(Bomb bomb) {
        bomb_ = bomb;
        return *this;
    }

    Person build() {
        Person person;
        return buildPerson(person);
    }

private:
    friend Person;
    Armor armor_ = Armor();
    Knife knife_ = Knife();
    Pistol pistol_ = Pistol();
    Gun gun_ = Gun();
    Grenade grenade_ = Grenade();
    SappersKit sappersKit_ = SappersKit();
    Bomb bomb_ = Bomb();

    Person &buildPerson(Person &person) {
        person.armor = armor_;
        person.knife = knife_;
        person.pistol = pistol_;
        person.gun = gun_;
        person.grenade = grenade_;
        person.sappersKit = sappersKit_;
        person.bomb = bomb_;
    }
};

class Terrorist {
public:
    Terrorist(Person person) : person(person) {};
private:
    Person person;
};

class SpecialSoldier {
public:
    SpecialSoldier(Person person) : person(person) {};
private:
    Person person;
};

int main() {
    std::cout << "terrorist" << std::endl;
    Terrorist terrorist = Terrorist(
            Builder()
                    .buildArmor(Armor(1))
                    .buildBomb(Bomb(1))
                    .buildGrenade(Grenade(1))
                    .buildGun(Gun(1))
                    .buildKnife(Knife(1))
                    .buildPistol(Pistol(1))
                    .buildSappersKit(SappersKit(1))
                    .build());
    std::cout << "specialSoldier" << std::endl;
    SpecialSoldier specialSoldier = SpecialSoldier(
            Builder()
                    .buildArmor(Armor(1))
                    .buildBomb(Bomb(1))
                    .buildGrenade(Grenade(1))
                    .buildGun(Gun(1))
                    .buildKnife(Knife(1))
                    .buildPistol(Pistol(1))
                    .buildSappersKit(SappersKit(1))
                    .build());
    return 0;
}
