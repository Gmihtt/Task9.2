#include <iostream>

class Armor {
public:
    Armor(int num) : num(num) {
        std::cout << "Armor; count: " << num << std::endl;
    }

    int num;
};

class Knife {
public:
    Knife(int num) : num(num) {
        std::cout << "Knife; count: " << num << std::endl;
    }

    int num;
};

class Pistol {
public:
    Pistol(int num) : num(num) {
        std::cout << "Pistol; count: " << num << std::endl;
    }

    int num;
};

class Gun {
public:
    Gun(int num) : num(num) {
        std::cout << "Gun; count: " << num << std::endl;
    }

    int num;
};

class Grenade {
public:
    Grenade(int num) : num(num) {
        std::cout << "Grenade; count: " << num << std::endl;
    }

    int num;
};

class SappersKit {
public:
    SappersKit(int num) : num(num) {
        std::cout << "SappersKit; count: " << num << std::endl;
    }

    int num;
};

class Bomb {
public:
    Bomb(int num) : num(num) {
        std::cout << "Bomb; count: " << num << std::endl;
    }

    int num;
};

class Person {
public:
    Person(
            Armor armor,
            Knife knife,
            Pistol pistol,
            Gun gun,
            Grenade grenade,
            SappersKit sappersKit,
            Bomb bomb) :
            armor(armor),
            knife(knife),
            pistol(pistol),
            gun(gun),
            grenade(grenade),
            sappersKit(sappersKit),
            bomb(bomb) {}

    Armor armor = Armor(0);
    Knife knife;
    Pistol pistol;
    Gun gun;
    Grenade grenade;
    SappersKit sappersKit;
    Bomb bomb;
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
        Person person = Person(
                armor_,
                knife_,
                pistol_,
                gun_,
                grenade_,
                sappersKit_,
                bomb_);
        return buildPerson(person);
    }

private:
    friend Person;
    Armor armor_ = Armor(0);
    Knife knife_ = Knife(0);
    Pistol pistol_ = Pistol(0);
    Gun gun_ = Gun(0);
    Grenade grenade_ = Grenade(0);
    SappersKit sappersKit_ = SappersKit(0);
    Bomb bomb_ = Bomb(0);

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
