/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &textureFile, sf::IntRect rect) :
_speed(3.0), _sprint(1.0), _stamina(100.0), _craftOpen(0), _rectSprite(rect)
{
    this->_texture.loadFromFile(textureFile);
    this->_sprite = sf::Sprite(this->_texture, this->_rectSprite);
    this->_shadow = sf::Sprite(this->_texture, this->_rectSprite);
    this->_shadow.setRotation(30);
    this->_shadow.setColor(sf::Color(0, 0, 0, 160));
    this->_shadow.move(27, -23);
    this->_udlrDir.fill(false);

    this->_sprite.setScale(0.4, 0.4);
    this->_shadow.setScale(0.4, 0.6);
    this->_sprite.setPosition(500, 500);
}

Character::~Character() {}

void Character::move(std::vector<sf::FloatRect> collides)
{
    sf::Vector2f delta = sf::Vector2f(0, 0);
    if (isMoving(UP)) // UP
        delta += sf::Vector2f(0, (-1 * _speed) * _sprint);
    else if (isMoving(DOWN)) // DOWN
        delta += sf::Vector2f(0, _speed * _sprint);
    else if (isMoving(LEFT))// LEFT
        delta += sf::Vector2f((-1 * _speed) * _sprint, 0);
    else if (isMoving(RIGHT)) // RIGHT
        delta += sf::Vector2f(_speed * _sprint, 0);
    sf::FloatRect new_pos = sf::FloatRect(
        _sprite.getGlobalBounds().left + delta.x,
        _sprite.getGlobalBounds().top + delta.y,
        _sprite.getGlobalBounds().width,
        _sprite.getGlobalBounds().height
    );
    for (int i = 0; i < collides.size(); i++){
        if (new_pos.intersects(collides[i]))
            return;
    }
    this->setSprint(isSprinting());
    if (this->isMoving())
        this->useStamina(this->isSprinting() ? 0.5 : 0.16);
    else
        this->restoreStamina(0.25);
    this->_sprite.move(delta);
    this->_shadow.move(delta);
}

bool Character::isMoving(moveDir direction)
{
    if (direction == NONE && \
    std::find(_udlrDir.begin(), _udlrDir.end(), true) != _udlrDir.end())
        return (true);
    if ((direction == UP && _udlrDir[0]) || \
    (direction == DOWN && _udlrDir[1]) || \
    (direction == LEFT && _udlrDir[2]) || \
    (direction == RIGHT && _udlrDir[3]))
        return (true);
    return (false);
}

// Getters

sf::Texture &Character::getTexture()
{
    return (this->_texture);
}

sf::Sprite &Character::getSprite()
{
    return (this->_sprite);
}

sf::Vector2f Character::getPos()
{
    return this->getSprite().getPosition();
}

sf::IntRect &Character::getRect()
{
    return (this->_rectSprite);
}

int Character::getHeight() const
{
    return (this->_sprite.getPosition().y + \
    this->_sprite.getGlobalBounds().height);
}

int Character::getStamina(void) const
{
    return (this->_stamina);
}

Stuff *Character::getStuff(void)
{
    return (&this->_stuff);
}

// Setters

void Character::setNewTexture(std::string textureFile)
{
    this->_texture.loadFromFile(textureFile);
    this->_sprite.setTexture(this->_texture);
    this->_shadow.setTexture(this->_texture);
    this->_shadow.setColor(sf::Color::Black);
}

void Character::useStamina(float consume)
{
    if (consume < 0)
        return;
    this->_stamina -= consume;
    if (this->_stamina < 0)
        this->_stamina = 0;
}

void Character::restoreStamina(float restore)
{
    if (restore < 0)
        return;
    this->_stamina += restore;
    if (this->_stamina > 100)
        this->_stamina = 100;
}

void Character::setDirection(Character::moveDir direc, bool state)
{
    if (direc == UP)
        _udlrDir[0] = state;
    else if (direc == DOWN)
        _udlrDir[1] = state;
    else if (direc == LEFT)
        _udlrDir[2] = state;
    else if (direc == RIGHT)
        _udlrDir[3] = state;
}

void Character::setSprint(const bool &state)
{
    if (!this->isMoving())
        return;
    this->_sprint = 1.0;
    if (state && this->_stamina > 0)
        this->_sprint = 1.0 + (this->_stamina / 100);
}

// Animations

void Character::move_rect(void)
{
    if (this->isMoving()) {
        if (this->_rectSprite.left == _rectSprite.width * 2)
            this->_rectSprite.left = _rectSprite.width;
        else
            this->_rectSprite.left = _rectSprite.width * 2;
    } else
        this->_rectSprite.left = 0;
    this->_sprite.setTextureRect(this->_rectSprite);
    this->_shadow.setTextureRect(this->_rectSprite);
}

void Character::change_orientation(void)
{
    if (this->isMoving(UP))
        this->_rectSprite.top = _rectSprite.height * 2;
    else if (this->isMoving(DOWN))
        this->_rectSprite.top = 0;
    else if (this->isMoving(LEFT))
        this->_rectSprite.top = _rectSprite.height;
    else if (this->isMoving(RIGHT))
        this->_rectSprite.top = _rectSprite.height * 3;
    this->_sprite.setTextureRect(this->_rectSprite);
}

bool Character::isSprinting(void) const
{
    if (this->_sprint == 1.0)
        return (false);
    return (true);
}

// Events

void Character::proximaObject(std::vector<sf::Sprite> &obj)
{
    sf::FloatRect objRect;
    std::vector<sf::Sprite>::iterator to_delete;

    for (auto it = obj.begin(); it != obj.end(); ++it) {
        objRect = it->getGlobalBounds();
        sf::FloatRect tmp = sf::FloatRect(
                this->_sprite.getGlobalBounds().left - 10,
                this->_sprite.getGlobalBounds().top - 10
                + this->_sprite.getGlobalBounds().height / 1.5,
                this->_sprite.getGlobalBounds().width + 20,
                21
        );
        if (tmp.intersects(objRect)) {
            int tmp = it->getLocalBounds().width;
            if (tmp == 356)
                *static_cast<Ressources *>(this->_stuff._ressources[0]) << 1;
            if (tmp == 548) {
                *static_cast<Ressources *>(this->_stuff._ressources[1]) << 1;
                if (random()%10 <= 4)
                    *static_cast<Ressources *>(this->_stuff._ressources[2]) << 1;
            }
            if (tmp == 667) {
                *static_cast<Ressources *>(this->_stuff._ressources[0]) << 3;
            }
            // DEBUG PRINT TO SEE INV
//            std::cout << (*static_cast<Ressources *>(this->_stuff._ressources[0])).getNumber() << " " \
//             << (*static_cast<Ressources *>(this->_stuff._ressources[1])).getNumber() << " " \
//             << (*static_cast<Ressources *>(this->_stuff._ressources[2])).getNumber() << " " \
//            << (*static_cast<Ressources *>(this->_stuff._ressources[3])).getNumber() << std::endl;
            obj.erase(it);
            return;
        }
    }
}

void Character::getEvents(sf::Event &event, std::vector<sf::Sprite> &obj)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left)
            this->setDirection(Character::LEFT, true);
        if (event.key.code == sf::Keyboard::Right)
            this->setDirection(Character::RIGHT, true);
        if (event.key.code == sf::Keyboard::Up)
            this->setDirection(Character::UP, true);
        if (event.key.code == sf::Keyboard::Down)
            this->setDirection(Character::DOWN, true);
        if (event.key.code == sf::Keyboard::Space)
            this->setSprint(true);
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left)
            this->setDirection(Character::LEFT, false);
        if (event.key.code == sf::Keyboard::Right)
            this->setDirection(Character::RIGHT, false);
        if (event.key.code == sf::Keyboard::Up)
            this->setDirection(Character::UP, false);
        if (event.key.code == sf::Keyboard::Down)
            this->setDirection(Character::DOWN, false);
        if (event.key.code == sf::Keyboard::Space)
            this->setSprint(false);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        this->proximaObject(obj);
        this->printData();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        this->_craftOpen = true;
}

// Craft
void Character::craftItem(Stuff &stuff, Items::itemType item)
{
    if (static_cast<Items *>(stuff._items[item])->getAvaible())
        return;
    this->_crafter.craftIt(stuff, item);
}

// Debug
void Character::printData(void)
{
    std::vector<Object *> ress = (_stuff._ressources);
    std::vector<Object *> item = (_stuff._items);

    std::cout << "\nWood:\t" << static_cast<Ressources *>(ress[0])->getNumber() << std::endl;
    std::cout << "Rock:\t" << static_cast<Ressources *>(ress[1])->getNumber() << std::endl;
    std::cout << "Steel:\t" << static_cast<Ressources *>(ress[2])->getNumber() << std::endl;
    std::cout << "PJul:\t" << static_cast<Ressources *>(ress[3])->getNumber() << std::endl;

    std::cout << "\nAxe:\t" << static_cast<Items *>(item[0])->getAvaible() << std::endl;
    std::cout << "Pickaxe:\t" << static_cast<Items *>(item[1])->getAvaible() << std::endl;
    std::cout << "Torch:\t" << static_cast<Items *>(item[2])->getAvaible() << std::endl;
    std::cout << "Generator:\t" << static_cast<Items *>(item[3])->getAvaible() << std::endl;
}