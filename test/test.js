var myObj = { "name": "runoob", "alexa": "10000", "site": null };
for (x in myObj) {
    document.getElementsById("demo").innerHTML += x + "<br>";
}
myObj = {
    "name": "runoob",
    "alexa": "10000",
    "sites": {
        "site1": "www.runoob.com",
        "site2": "m.runoob.com",
        "site3": "c.runoob.com"
    }
};
x = myObj.sites.site1;
// ����
// x = myObj.sites[site1];
// x = myObj["sites"]["site1"];

delete myObj.site.site1;
//or
delete myObj.site["site1"];

var my = { "name": "��վ", "num": 3, "sites": ["Google", "Runoob", "Taobao"] }, x;
x = my["sites"][0]
//or
// x = my.sites[0];
for (i in my.sites) {
    x += my.sites[i] + "<br>";
}
for (i = 0; i < my.sites.length; i++) {
    x += my.sites[i] + "<br>";
}

myObj = {
    "name": "��վ",
    "num": 3,
    "sites": [
        { "name": "Google", "info": ["Android", "Google ����", "Google ����"] },
        { "name": "Runoob", "info": ["����̳�", "���񹤾�", "����΢��"] },
        { "name": "Taobao", "info": ["�Ա�", "����"] }
    ]
}
//access the array
for (i in myObj.sites) {
    x += "<h1>" + myObj.sites[i], name + "</h1>";
    for (j in myObj.sites[i].info) {
        x += myObj.sites[i].info[j] + "<br>";
    }
}

var he = {
    "name": "��վ",
    "num": 3,
    "sites": ["Google", "Runoob", "Taobao"]
}
//change the element
he.sites[1] = "Github";

//delete the element
delete he.sites[1];