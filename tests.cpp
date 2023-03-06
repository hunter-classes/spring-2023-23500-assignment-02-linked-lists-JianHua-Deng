#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"




TEST_CASE("OList class"){
    
    OList *olist = new OList(); // -10 1 3 10 15 65 100
    olist->insert("15");
    olist->insert("65");
    olist->insert("1");
    olist->insert("3");
    olist->insert("100");
    olist->insert("-10");
    olist->insert("10");


    OList *olist2 = new OList(); // 0 10 15 25 60 95
    olist2->insert("95");
    olist2->insert("60");
    olist2->insert("25");
    olist2->insert("15");
    olist2->insert("10");
    olist2->insert("0");

    //Check toString and if insert was done correctly function
    CHECK(olist->toString() == "-10-->1-->3-->10-->15-->65-->100-->nullptr");
    CHECK(olist2->toString() == "0-->10-->15-->25-->60-->95-->nullptr");

    //Check insert and contains function
    CHECK(olist->contains("-10") == true);
    CHECK(olist->contains("15") == true);
    CHECK(olist->contains("65") == true);
    CHECK(olist->contains("1") == true);
    CHECK(olist->contains("3") == true);
    CHECK(olist->contains("100") == true);
    CHECK(olist->contains("10") == true);

    //Check remove function
    CHECK(olist->remove(3) == true);
    CHECK(olist->remove(5) == true);
    CHECK(olist->remove(0) == true);

    CHECK(olist->contains("10") == false);
    CHECK(olist->contains("100") == false);
    CHECK(olist->contains("-10") == false);
    
    //Check get function
    CHECK(olist2->get(3) == "25");
    CHECK(olist2->get(5) == "95");
    CHECK(olist2->get(0) == "0");

    //Check reverse function
    olist->reverse();
    olist2->reverse();
    CHECK(olist->toString() == "65-->15-->3-->1-->nullptr");
    CHECK(olist2->toString() == "95-->60-->25-->15-->10-->0-->nullptr");

}
