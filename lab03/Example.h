class Example {
public:
   Example(double value);
   ~Example();
   
   void setValue(double value);
   double getValue();

private:
   double* ptrValue;
};