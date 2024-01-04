#include <iostream>
#include <string>
#include <assert.h>
#include <sstream>
#include <vector>
using namespace std;
class HTMLElement
{
public:
	HTMLElement();
	~HTMLElement();
    string getHTMLString();
    friend ostream& operator<<(ostream& output, HTMLElement& element)
    {
        output << element.getHTMLString();
        return output;
    }
protected:
    string element_html;
};
class HTMLImage:public HTMLElement
{
public:
	HTMLImage(string);
	~HTMLImage();

private:

};
class HTMLParagraph:public HTMLElement
{
public:
	HTMLParagraph(string);
	~HTMLParagraph();

private:

};

template <typename T>
class HTMLBuilder
{
public:
    HTMLBuilder() {};
    ~HTMLBuilder() {};
    HTMLBuilder& operator+=(T elem)
    {
        if (elem == nullptr)
            throw std::runtime_error("Cannot add a null element!");
        elements.push_back(elem);
        return *this;
    }
    friend ostream& operator<<(ostream& output, HTMLBuilder& builder)
    {
        output << "<html><body>";
        for (auto element : builder.elements)
        {
            output << *element;
        }
        output << "</body></html>";
        return output;
    }
private:
    vector<T> elements;
};

HTMLParagraph::HTMLParagraph(string element)
{
    stringstream s;
    s << "<p>" << element << "</p>";
    this->element_html = s.str();
}

HTMLParagraph::~HTMLParagraph()
{
}

HTMLImage::HTMLImage(string image)
{
    stringstream s;
    s << "<img>" << image << "</img>";
    this->element_html = s.str();
}

HTMLImage::~HTMLImage()
{
}

HTMLElement::HTMLElement()
{

}

HTMLElement::~HTMLElement()
{
}

string HTMLElement::getHTMLString()// it will return the string of elemnt_html
{
    return this->element_html;
}

void fct1()
{
    HTMLElement* p1 = new HTMLParagraph{ "Examination" };
    assert(p1->getHTMLString() == "<p>Examination</p>");
    HTMLElement* p2 = nullptr;
    HTMLElement* i1 = new HTMLImage{ "a.jpg" };
    HTMLElement* i2 = new HTMLImage{ "b.jpg" };
    assert(i2->getHTMLString() == "<img>b.jpg</img>");
    HTMLBuilder<HTMLElement*> html{};
    try {
        html += p2;
        assert(false);
    }
    catch (runtime_error& e) {
        assert(strcmp(e.what(), "Cannot add a null element!") == 0);
    }

    ((html += p1) += i1) += i2;
    cout << html; // prints: <html><body><p>Examination</p><img>a.jpg</img><img>b.jpg</img></html></body>
    delete p1; delete p2;
    delete i1; delete i2;

}

int main()
{
    //std::cout << "Hello World!1\n";
    fct1();
    return 0;
}