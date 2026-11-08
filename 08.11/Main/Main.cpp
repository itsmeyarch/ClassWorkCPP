#include <iostream>
#include <memory>
#include <vector>

class Player {
private:
	int health;
	std::string name;
public:
	Player(int health, std::string name) : health(health), name(name) {
		std::cout << "[LOG]: Player ctor\n";
	}

	~Player() {
		std::cout << "[LOG]: Player dtor\n";
	}

	void printPlayerData() const {
		std::cout << name << " " << health << '\n';
	}

};

class Texture {
private:
	std::string filename;
public:
	Texture(std::string filename) :filename(filename) {
		std::cout << "[LOG]: Loading texture file: " << filename << '\n';
	}
	~Texture() {
		std::cout << "[LOG]: Unload texture file: " << filename << '\n';
	}
	void use()const {
		std::cout << "Draw texture: " << filename << '\n';
	}
};

class GameObject {
private:
	std::string name;
	std::shared_ptr<Texture> texture;
public:
	GameObject(std::string name, std::shared_ptr<Texture> texture) : name(name), texture(texture) {
		std::cout << "[LOG] Create object " << name << '\n';
	}
	~GameObject() {
		std::cout << "[LOG] Destroy object " << name << '\n';
	}
	void render() const {
		std::cout << "[LOG] Rendering object " << name << '\n';
		texture.get()->use();
	}
};

class Child;

class Parent {
public:
	std::string name;
	std::shared_ptr<Child> child;

	Parent(std::string name, std::shared_ptr<Child> child) :name(name), child(child) {
		std::cout << "[LOG]: Parent ctor\n";
	}
	~Parent() {
		std::cout << "[LOG]: Parent dtor\n";
	}
};

class Child {
public:
	std::string name;
	std::weak_ptr<Parent> parent;

	Child(std::string name) : name(name) {
		std::cout << "[LOG]: Child ctor\n";
	}
	~Child() {
		std::cout << "[LOG]: Child dtor\n";
	}

	void printChild() const {
		if (std::shared_ptr<Parent> p = parent.lock()) {
			std::cout << p->name << '\n';
		}
		else {
			std::cout << "Parent was deleted\n";
		}
	}
};

int main()
{
	std::shared_ptr<Parent> parent = std::make_shared<Parent>("parent", std::make_shared<Child>("child"));
	parent.get()->child.get()->parent = parent;

	parent->child->printChild();

	//std::shared_ptr<Texture> texture = std::make_shared<Texture>("tree_texture.png");

	//GameObject tree1("tree1", texture);
	//GameObject tree2("tree2", texture);
	//GameObject tree3("tree3", texture);

	//tree1.render();
	//tree2.render();
	//tree3.render();

	//std::vector<GameObject> go(100);


}