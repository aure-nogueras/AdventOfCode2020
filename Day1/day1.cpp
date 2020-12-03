#include <iostream>
#include <vector>

using namespace std;

int multiplyTwoNumbers(vector<int> list){
    int suma = 0;
    int numberOne = -1;
    int numberTwo = -1;
    bool found = false;
    for(auto i=0; i<list.size() && !found; i++){
        for(auto j=0; j<list.size() && !found; j++){
            if(i!=j){
                suma = list[i] + list[j];
                if(suma == 2020){
                    numberOne = list[i];
                    numberTwo = list[j];
                    found = true;
                }
            }
            suma = 0;
        }
    }
    int multiply = numberOne * numberTwo;
    return multiply;
}

int multiplyThreeNumbers(vector<int> list){
    int suma = 0;
    int numberOne = -1;
    int numberTwo = -1;
    int numberThree = -1;
    bool found = false;
    for(auto i=0; i<list.size() && !found; i++){
        for(auto j=0; j<list.size() && !found; j++){
            for(auto k=0; k<list.size() && !found; k++){
                if(i!=j && j!=k && i!=k){
                    suma = list[i] + list[j] + list[k];
                    if(suma == 2020){
                        numberOne = list[i];
                        numberTwo = list[j];
                        numberThree = list[k];
                        found = true;
                    }
                }
                suma = 0;
            }
        }
    }
    int multiply = numberOne * numberTwo * numberThree;
    return multiply;
}

int main(int argc, char * argv[]){
    vector<int> list;
    list.push_back(1531);
    list.push_back(1959);
    list.push_back(1344);
    list.push_back(1508);
    list.push_back(1275);
    list.push_back(1729);
    list.push_back(1904);
    list.push_back(1740);
    list.push_back(1977);
    list.push_back(1992);
    list.push_back(1821);
    list.push_back(1647);
    list.push_back(1404);
    list.push_back(1893);
    list.push_back(1576);
    list.push_back(1509);
    list.push_back(1995);
    list.push_back(1637);
    list.push_back(1816);
    list.push_back(1884);
    list.push_back(1608);
    list.push_back(1943);
    list.push_back(1825);
    list.push_back(1902);
    list.push_back(1227);
    list.push_back(1214);
    list.push_back(1675);
    list.push_back(1650);
    list.push_back(1752);
    list.push_back(1818);
    list.push_back(862);
    list.push_back(2006);
    list.push_back(227);
    list.push_back(1504);
    list.push_back(1724);
    list.push_back(1961);
    list.push_back(1758);
    list.push_back(1803);
    list.push_back(1991);
    list.push_back(1126);
    list.push_back(1909);
    list.push_back(1643);
    list.push_back(1980);
    list.push_back(1889);
    list.push_back(811);
    list.push_back(1699);
    list.push_back(1654);
    list.push_back(1734);
    list.push_back(1770);
    list.push_back(1754);
    list.push_back(1828);
    list.push_back(1811);
    list.push_back(1997);
    list.push_back(1767);
    list.push_back(1854);
    list.push_back(1653);
    list.push_back(1800);
    list.push_back(1762);
    list.push_back(1962);
    list.push_back(1797);
    list.push_back(877);
    list.push_back(1660);
    list.push_back(1895);
    list.push_back(1939);
    list.push_back(1679);
    list.push_back(1496);
    list.push_back(1606);
    list.push_back(1262);
    list.push_back(1727);
    list.push_back(2005);
    list.push_back(1796);
    list.push_back(1595);
    list.push_back(1846);
    list.push_back(1822);
    list.push_back(1974);
    list.push_back(1829);
    list.push_back(1347);
    list.push_back(1341);
    list.push_back(1875);
    list.push_back(1726);
    list.push_back(1963);
    list.push_back(1659);
    list.push_back(337);
    list.push_back(1826);
    list.push_back(1777);
    list.push_back(1523);
    list.push_back(1979);
    list.push_back(1805);
    list.push_back(1987);
    list.push_back(2009);
    list.push_back(1993);
    list.push_back(374);
    list.push_back(1546);
    list.push_back(1706);
    list.push_back(1748);
    list.push_back(1743);
    list.push_back(1725);
    list.push_back(281);
    list.push_back(1317);
    list.push_back(1839);
    list.push_back(1683);
    list.push_back(1794);
    list.push_back(1898);
    list.push_back(1824);
    list.push_back(1960);
    list.push_back(1292);
    list.push_back(1876);
    list.push_back(1760);
    list.push_back(1956);
    list.push_back(1701);
    list.push_back(1565);
    list.push_back(1680);
    list.push_back(1932);
    list.push_back(1632);
    list.push_back(1494);
    list.push_back(1630);
    list.push_back(1838);
    list.push_back(1863);
    list.push_back(1328);
    list.push_back(1490);
    list.push_back(1751);
    list.push_back(1707);
    list.push_back(1567);
    list.push_back(1917);
    list.push_back(1318);
    list.push_back(1861);
    list.push_back(519);
    list.push_back(1716);
    list.push_back(1891);
    list.push_back(1636);
    list.push_back(1684);
    list.push_back(1200);
    list.push_back(1933);
    list.push_back(1911);
    list.push_back(1809);
    list.push_back(1967);
    list.push_back(1731);
    list.push_back(1921);
    list.push_back(1827);
    list.push_back(1663);
    list.push_back(1720);
    list.push_back(1976);
    list.push_back(1236);
    list.push_back(1986);
    list.push_back(1942);
    list.push_back(1656);
    list.push_back(1733);
    list.push_back(1541);
    list.push_back(1640);
    list.push_back(1518);
    list.push_back(1897);
    list.push_back(1676);
    list.push_back(1307);
    list.push_back(1978);
    list.push_back(1998);
    list.push_back(1674);
    list.push_back(1817);
    list.push_back(1845);
    list.push_back(1658);
    list.push_back(1639);
    list.push_back(1842);
    list.push_back(1929);
    list.push_back(1972);
    list.push_back(2010);
    list.push_back(1951);
    list.push_back(858);
    list.push_back(1928);
    list.push_back(1562);
    list.push_back(1787);
    list.push_back(1916);
    list.push_back(1561);
    list.push_back(1694);
    list.push_back(1944);
    list.push_back(1922);
    list.push_back(1882);
    list.push_back(1691);
    list.push_back(589);
    list.push_back(1940);
    list.push_back(1624);
    list.push_back(1570);
    list.push_back(1557);
    list.push_back(1791);
    list.push_back(1492);
    list.push_back(1919);
    list.push_back(1615);
    list.push_back(1571);
    list.push_back(1657);
    list.push_back(1984);
    list.push_back(1521);
    list.push_back(1766);
    list.push_back(1790);
    list.push_back(1782);
    list.push_back(1874);
    list.push_back(1198);
    list.push_back(1764);
    list.push_back(1278);
    list.push_back(1688);
    list.push_back(1905);
    list.push_back(1786);
    list.push_back(1281);

    cout << "La primera solución es: " << multiplyTwoNumbers(list) << endl;
    cout << "La segunda solución es: " << multiplyThreeNumbers(list) << endl;

}