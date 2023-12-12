// secrets.h
#include <pgmspace.h>

#define SECRET
#define THINGNAME "watherpump1"

const char WIFI_SSID[] = "Frontier5664";
const char WIFI_PASSWORD[] = "0546758114";
const char AWS_IOT_ENDPOINT[] = "alciucqxncdzf-ats.iot.us-west-2.amazonaws.com";


// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate - certificate.pem.crt
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAMyTuWquT7on0UQpccWBlpKKJ64+MA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzEyMTAxNDQ2
MTBaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC64v7+82IPEx2M9YAG
HUhlLBiYOmEegsFB93Sxzs2l3ikhP4VK9L2mOMEQ9J8y3du229d2Mu7dz5JbVEgh
g861A7cpiG33/3oySEXcLc0itPua6S8ti+9QJvTvq6Q0jJaCPSk2690A6mIM0KG8
44Xc/U14+aMqcmxgN/N4o2qk7DgeiNQZ7Y4aEVS7eqtUu6pVIlUKqgkiblRXkHTF
UoBuqMarqk7FTgBQ0JHQMOjmiQFmH4VXxicWrQ7XgoWanxnf2y6hRSZN7062AFgm
rCc+4NSQf9PykvmXy5TQtj3kL7tldlIrZ7SaEoCD3Tc4wkRL3cO6qJHUaSXs+x9v
bgwDAgMBAAGjYDBeMB8GA1UdIwQYMBaAFA4U560rYo3kfkQRmwtIGEIfzXXBMB0G
A1UdDgQWBBToA1EVwvNCe0YWj5JI5B5jjFBw2jAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEA1xcFvX+bvZ5Djp3hlSZ7q5X4
pQAIGhbm+7lumoo1KZqPsMs3UKdeml3uNaHE/1AGlcV0p+2f4cjvDc3elCrB+EoF
oPZPBXL/aQwyHHlQu9bB8YUSvnOgXp47Ek1OUmQvksStkl7+eiP/+C4vwbR+ZRs9
vaXXVOPqdgg4vtucD87fVgIFUUnLkUM/6OS5Geh+K3ewmBw3JvyDBFJqWjfvz1XO
H4HyEaDniPZgtbj3CH3He4e99ITXj6mrIcVHn9Q9zqfnKCXj1nz71DO0Jj79xl/a
mA3YMkbpphK10YFIrhPg5sYxXFZZ26ZB8pNSZjWtZPi7Q/0eoHtFalM6OmHRpQ==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAuuL+/vNiDxMdjPWABh1IZSwYmDphHoLBQfd0sc7Npd4pIT+F
SvS9pjjBEPSfMt3bttvXdjLu3c+SW1RIIYPOtQO3KYht9/96MkhF3C3NIrT7mukv
LYvvUCb076ukNIyWgj0pNuvdAOpiDNChvOOF3P1NePmjKnJsYDfzeKNqpOw4HojU
Ge2OGhFUu3qrVLuqVSJVCqoJIm5UV5B0xVKAbqjGq6pOxU4AUNCR0DDo5okBZh+F
V8YnFq0O14KFmp8Z39suoUUmTe9OtgBYJqwnPuDUkH/T8pL5l8uU0LY95C+7ZXZS
K2e0mhKAg903OMJES93DuqiR1Gkl7Psfb24MAwIDAQABAoIBAF3eoqJAcWKNAWzJ
6xInJzPaIEhmGl4O4y9VMgIVk+naWuJeW384ywFwxFjV5hjQowmIBwNRtfUny6Wg
AdMDt5HoWdm8sy+73Q7gimZ7guwJ5875jT7daMjjqGex2PqkGv0z5z203v8Uu0cg
i/yqc5R6jq1TBofNjW4O7HYN7wUC3I2CkW+fogVlgz8U0BByl6kDR3EaJ6DdFtWc
e31vaSKK+hwsudLVS8nUzQj2urzbOgY6mWG0/Bk+5CfxqCAYVwApMarulZRLsD4e
CCiEICk71yLJPp817pZU/pGUlser1Xh8RWWUBYY71mToB5p+swosyZuwy7Cg1R52
ZUpjzfECgYEA8olecDdrOoOWMeIK+0apOdlabhwb5a7LauVs17cAIdxiFvFwdbkZ
fxS9zPahOAEb7iwY48RkxIh5REqqGVGVxaL4X7gF9HnWYwEX3rmHAIWAkQSVj2HG
kny3q9Mm7lE/laiV52JWLpF5Lhtx8XJ8YQdNx7yTKCAK/6ittVN0d28CgYEAxULM
q9HTvOUECSJiFbRuLMPtef11euMi0CpdF38AhVjtqr3EBx8YIT5O+JFssoBfkUth
DGWWUOppwILwaAqBrQPZQnGa5Vf32WLEL2bMBdE4UZ4sHJa8VlYzdjbpyNRSTG7k
UnHk2C/QpFLvma7krh0akgVQIiFlVllds4RhCq0CgYEA4EbtIIHu01Y5PnmTxBbs
iAUZHXc6yOMhUgFD7BpasfU0c5jicMow7JYGiZGLNdm4tT7r6TuEH0VANkmBEBak
k/UHDqSCRTehaz3oj9oqH+5UHEYL82HsGSvhQK/qcTiKvt79d9E0dq2pTFyuuiIv
KB5z637S6ajv4shdka7RpVsCgYEAvvbVFz1Roxt+Va1wkRyUUEf43VEu6yF6cVWh
u35arb0SkGmXnWFPxdcBMofuV7wJSKpVsF+kLn9Qk2rve3k4YptIN5etYXtQ2KVR
0aXNu4/42qKqh56xg09+EGJG3wIVDiOIa/wQk+1uKbaUeA4lGh3YvCXilrgH15k6
KfDs1R0CgYBo32hZEc56dqJKxtwxtg6pNYOhqoK69tVJDmyT43DJ8cb+kNZcVFrc
RFHB+YVuxf6i9U3Z4whuLcc7Hhls8bRxZ+JkatdGITexT4Rn5DCYfaGAjW4k4ar7
VW8nH+LHK+PtQ9EJJ58kbb902Ixw+4mTgmuBnpChy01JqRBL+RbcQQ==
-----END RSA PRIVATE KEY-----
)KEY";