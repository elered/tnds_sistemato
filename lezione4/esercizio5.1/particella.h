class particella {

    public:

    particella();
    particella(double massa, double carica);
    ~particella();

    double getmassa() const {
        return m_massa;
    }

    double getcarica() const {
        return m_carica;
    }

    void print() const;

    protected:

    double m_massa;
    double m_carica;
};

class elettrone : public particella {

    public:

    elettrone(): particella(9.1093826E-31, -1.60217653E-19) {};
    ~elettrone();
    void print() const;

};