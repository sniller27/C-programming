//struct with arrays for date and weather values
struct Weather_Values {
    char date[255][31];
    float weather_value[31];
};

//struct for dataset for at given year
struct Year {
    struct Weather_Values temperature;
    struct Weather_Values rain;
};