#include <iostream>
#include <memory>

struct Student {
    std::string m_id;
    std::string m_name;
};

class SmartPtr {
private:
    Student* m_data {nullptr};
public:
    SmartPtr() = default;
    explicit SmartPtr(Student* data) : m_data(data) {}

    //move constructor - moves pointer ownership and removes from old source
    SmartPtr(SmartPtr&& ptr) noexcept {
        m_data = ptr.m_data;
        ptr.m_data = nullptr;
    }
    ~SmartPtr() {
        if (m_data) std::cout << "deallocating student" << std::endl;
        delete m_data;
    }
    Student* get() { return m_data; }
    static SmartPtr make_smartptr() {
        std::cout << "allocating new student" << std::endl;
        return SmartPtr(new Student());
    }
    Student* operator->() noexcept { return m_data; }
    bool operator==(Student* s) { return m_data == s; }


};

int main() {
    auto print = [](auto& desc, auto& s) {
        std::cout << desc << s->m_name << " (" << s->m_id << ") " << std::endl;
    };
    {
        // regular pointer
        auto s = new Student();
        s->m_id = "w0183220";
        s->m_name = "john";
        print("OLD PTR: ", s);
        // don't forget to delete!!
        delete s;
    }
    std::cout << "------------------" << std::endl;
    {
        auto sp1 = SmartPtr::make_smartptr();
        sp1->m_id = "w0183220";
        sp1->m_name = "jane";
        print("ORIGINAL: ", sp1);

        // borrowed reference to the data
        auto student = sp1.get();
        print("referenced: ", student);

        // give ownership of the data to another variable
        auto sp2 = std::move(sp1);
        print("Moved: ", sp2);

        // sp1 is now empty - gives a null pointer exception
        auto s = (sp1 == nullptr ? "Empty" : sp1->m_name + "( " + sp1->m_id + ") ");
        std::cout << "Illegal: " << s << std::endl;
    }
    {
        std::cout << "------------------" << std::endl;
        // STL version(standard library)
        auto up1 = std::make_unique<Student>();
        up1->m_id = "w0183220";
        up1->m_name = "jane";
        print("UNIQUE PTR: ", up1);

        // reference the data
        auto student = up1.get();
        print("referenced: ", student);

        // give ownership of the data to another variable
        auto up2 = std::move(up1);
        print("Moved: ", up2);

        // up1 is now empty - gives a null pointer exception
        auto s = (up1 == nullptr ? "Empty" : up1->m_name + "( " + up1->m_id + ") ");
        std::cout << "Illegal: " << s << std::endl;
    }
    return 0;
}
