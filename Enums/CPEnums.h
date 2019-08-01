#pragma once

enum Method { M_GET, M_POST, M_PUT, M_DELETE};
enum ContentType { JSON, XML, PERCENT_ENC};
enum Action { Create, Update, Delete};
enum CityProperty { CP_Name, CP_Position, CP_Forecasts, CP_City};
enum GeoPointProperty { GP_Latitude, GP_Longitude, GP_GeoPoint };
enum WeatherProperty { WP_Date, WP_Description, WP_Temperature,  WP_Pressure, WP_WindSpeed, WP_Humidity, WP_Weather };
enum MenuType { Main, InputName, InputLatitude, InputLongitude, InputDate };