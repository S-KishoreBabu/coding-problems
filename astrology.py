from kerykeion import AstrologicalSubject

subject = AstrologicalSubject(
    "John Doe",   # name
    1992,         # year
    7,            # month
    22,           # day
    9,            # hour
    30,           # minute
    11.0168,      # latitude
    76.9558,      # longitude
    5.5           # timezone
)

print("Sun sign:", subject.sun_sign)
print("Moon sign:", subject.moon_sign)
print("Ascendant:", subject.ascendant)
