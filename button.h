#ifndef BUTTON_H
#define BUTTON_H

void nothing();

class button
{
    public:
        button();
        virtual ~button();

    protected:

    private:
        int width,height;
        void onClick();
        void onHover();
};

#endif // BUTTON_H
