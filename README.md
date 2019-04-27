# VUObjektinisNO2

## Programos tikslas

- Pagal nuskaitytus arba įvestus studentų duomenis (namų darbų pažymius(vidurkį/medianą) ir egzamino rezultatus) suskaičiuoti **galutinius**, naudojant formulę (galutinis = 0.4 * vidurkis + 0.6 * egzaminas) 

## Įdiegimas (Unix kompiuteryje) 

- `git clone https://github.com/ToNyHasK/VUObjektinisNO2.git`
- `cd VUObjektinisNO2`

## Versijų istorija (changelog)

### [v1.2](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v1.2) - (2019-04-27)

**Pridėta**

- Operatorių overloadinimas, pagal trijų taisyklę

### [v1.1.1](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v1.1.1) - (2019-04-13)

**Pakeista**

- Struct į class

**Laikai(antroji strategija su vidurkiu)**

    **Struct**
    - Elapsed time(whole program, second strategy) with vector: 4.65151 s
    **Class**
    - Elapsed time(whole program, second strategy) with vector: 3.7908 s
    - 01 flag - 2.03059 s
    - 02 flag - 2.17917 s
    - 03 flag - 2.08763 s

### [v1.1](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v1.1) - (2019-03-26)

**Pataisyta**

- v1.0 neveikia su cmake, v1.1 turėtų veikti

### [v1.0](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v1.0) - (2019-03-24)

**Pridėta**

- CMakefile
- Antroji strategija

**Laikai**

	**Vidurkiu:**
		**Pirmoji strategija:**
			- Elapsed time(whole program, first strategy) with vector: 4.87426 s
			- Elapsed time(whole program, first strategy) with deque: 4.97473 s
			- Elapsed time(whole program, first strategy) with list: 4.19478 s
		**Antroji strategija:**
			- Elapsed time(whole program, second strategy) with vector: 4.65151 s
			- Elapsed time(whole program, second strategy) with deque: 4.91582 s
			- Elapsed time(whole program, second strategy) with list: 4.00226 s
	**Mediana**
		**Pirmoji strategija:**
			- Elapsed time(whole program, first strategy) with vector: 4.86205 s
			- Elapsed time(whole program, first strategy) with deque: 4.98566 s
			- Elapsed time(whole program, first strategy) with list: 4.18285 s
		**Antroji strategija:**
			- Elapsed time(whole program, second strategy) with vector: 4.67467 s
			- Elapsed time(whole program, second strategy) with deque: 4.90189 s
			- Elapsed time(whole program, second strategy) with list: 3.95339 s

**Apibendrinimas**

- Vector: antroji strategija su vectoriumi veikia grečiau, labiau apsimoka naudot antrą strategiją
- Deque: laiko kitimai minimalūs, grečiau pagal antrą strategiją
- List: naudojant antrą strategiją listas pagreitėja
- Overall: labiau apsimoka naudot antrą strategiją, atminties atžvilgiu ir laiko taupymu

### [v0.5.2](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.5.2) - (2019-03-24)

**Pridėta**

- Sort funkcija
- read from file funkcija

**Pataisyta**

- Pakeisti vektoriai
- Programa veikia, kaip nurodyta užduotyje

**Naujausi laikai**

- Elapsed time(whole program) with vector: 4.73548 s
- Elapsed time(whole program) with deque: 4.94371 s
- Elapsed time(whole program) with list: 4.13433 s


### [v0.5.1](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.5.1) - (2019-03-17)

**Pataisyta**

- Programa automatiškai apskaičiuoja laikus su skirtingais konteineriais **(vector, deque, list)**
- Greičiau veikianti programos versija

**Nauji laikai**

- Elapsed time(whole program) with vector: 4.1619 s
- Elapsed time(whole program) with deque: 4.66848 s
- Elapsed time(whole program) with list: 4.72436 s

### [v0.5](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.5) - (2019-03-12)

**Apie**

- Apskaičiuoti programos veikimo laiką naudojant skirtingus konteinerius

**Laikai**

- Su **vector**: 6.97499 s
- Su **deque**: 6.658 s
- Su **list**: 5.58647 s

**Pakeista**

- Ikelta versija yra su **link** ir **iteratoriais**

### [v0.4](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.4) - (2019-03-01)

**Apie**

- Generuojami penki failai, su **random** sugeneruotais studentų balais
- Sukuriami dar du failai (viename faile sudedami pažymiai >5, kitame <5)
- Taip pat skaiciuojamas programos veikimo laikas ir kiekvieno failo sukūrimo laikas

**Laikai**

- Pirmo failo: 0.000681 s
- Antro failo: 0.00798 s
- Trečio failo: 0.032946 s
- Ketvirto failo: 0.249309 s
- Penkto failo: 2.82796 s
- Visos programos: 6.97499 s

### [v0.3](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.3) - (2019-02-22)

***Pridėta***

- **Headers** files

**Koreguota**

- Didzioji dalis funkcijų perkelta į headers failus

### [v0.2.2](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.2.2) - (2019-02-19)

**Koreguota**

- Atnaujintas **README** failas
- Sutaisyta **sort** funkcija

### [v0.2.1](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.2.1) - (2019-02-19)

***Pridėta***

- Galimybė pasirinkti tarp įvedimo ir nuskaitymo iš failo
- **Sort** funkcija

**Koreguota**

- Pataisyta didžioji dalis funkcijų **(skaitymo iš failo, išvedimo, įvedimo)**

### [v0.2](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.2) - (2019-02-18)

***Pridėta***

- Nuskaitymas iš failo

### [v0.1.1](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.1.1) - (2019-02-25)

**Koreguota**

- Sutvarkytas kodas

### [v0.1](https://github.com/ToNyHasK/VUObjektinisNO2/releases/tag/v0.1) - (2019-02-17)

***Pridėta***

- Pirminė programos versija
