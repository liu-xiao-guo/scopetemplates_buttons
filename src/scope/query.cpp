#include <boost/algorithm/string/trim.hpp>

#include <scope/localization.h>
#include <scope/query.h>
#include <iostream>

#include <unity/scopes/Annotation.h>
#include <unity/scopes/CategorisedResult.h>
#include <unity/scopes/CategoryRenderer.h>
#include <unity/scopes/QueryBase.h>
#include <unity/scopes/SearchReply.h>
#include <unity/scopes/VariantBuilder.h>
#include <unity/scopes/CannedQuery.h>

#include <iomanip>
#include <sstream>

#include <QDebug>

const QString URI = "https://github.com/liu-xiao-guo/scopetemplates_release/blob/master/src/scope/query.cpp";
#define qstr(s) QString::fromStdString(s)

namespace sc = unity::scopes;
using namespace sc;
using namespace unity::scopes;
namespace alg = boost::algorithm;

using namespace std;
using namespace api;
using namespace scope;

const static string CAT_RENDERER1
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "grid",
            "card-layout": "vertical",
            "card-size" : "medium",
            "card-background": "#00FF00"
        },
        "components" :
        {
            "title" : "title",
            "art" : "art",
            "subtitle": "subtitle",
            "mascot": "mascot",
            "emblem": "emblem",
            "summary": "summary",
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

const static string CAT_RENDERER101
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "grid",
            "card-layout": "vertical",
            "card-size" : "large",
            "card-background": "#00FF00"
        },
        "components" :
        {
            "title" : "title",
            "art" : "art",
            "subtitle": "subtitle",
            "mascot": "mascot",
            "emblem": "emblem",
            "summary": "summary",
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};


const static string CAT_RENDERER2
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "grid",
            "card-layout": "horizontal",
            "card-size" : "large",
            "card-background": "#00FF00"
        },
        "components" :
        {
            "title" : "title",
            "art" : "art",
            "subtitle": "subtitle",
            "mascot": "mascot",
            "emblem": "emblem",
            "summary": "summary",
            "background": "background",
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

const static string CAT_RENDERER3 = R"(
{
        "schema-version": 1,
        "template": {
        "category-layout": "grid",
        "card-layout": "horizontal",
        "card-size": "medium",
        "card-background": "#00FF00"
        },
        "components": {
        "title": "title",
        "art" : {
        "field": "art"
        },
        "subtitle": "subtitle",
        "overlay-color": "overlay-color",
        "attributes": {
        "field": "attributes",
        "max-count": 2
        }
        }
        }
        )";

const static string CAT_RENDERER4
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "grid",
            "card-layout": "vertical",
            "card-size" : "medium"
        },
        "components" :
        {
            "title" : "title",
            "art" : "art",
            "subtitle": "subtitle",
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

const static string CAT_RENDERER5
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "grid",
            "card-layout": "vertical",
            "card-size" : "medium"
        },
        "components":
        {
            "title": "title",
            "subtitle": "subtitle",
            "overlay-color": "overlay-color",
            "art" : {
                "field": "art",
                "aspect-ratio": 2.0
            },
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

const static string CAT_RENDERER6
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "grid",
            "card-layout": "vertical",
            "card-size" : "medium"
        },
        "components":
        {
            "title": "title",
            "subtitle": "subtitle",
            "art" : {
                "field": "art",
                "aspect-ratio": 1.0
            },
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

const static string CAT_RENDERER7
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "grid",
            "card-layout": "vertical",
            "card-size" : "medium",
            "overlay": true

        },
        "components":
        {
            "title": "title",
            "subtitle": "subtitle",
            "art" : {
                "field": "art",
                "aspect-ratio": 1.0
            },
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

const static string CAT_RENDERER8
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "grid",
            "card-layout": "vertical",
            "card-size" : "medium"
        },
        "components" :
        {
            "title" : "title",
            "art" : "art",
            "subtitle": "subtitle",
            "mascot": "mascot",
            "emblem": "emblem",
            "summary": "summary",
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

const static string CAT_RENDERER9
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "carousel",
            "card-layout": "vertical",
            "card-size" : "medium"
        },
        "components" :
        {
            "title" : "title",
            "art" : "art",
            "subtitle": "subtitle",
            "mascot": "mascot",
            "emblem": "emblem",
            "summary": "summary",
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

const std::string CAT_RENDERER10 = R"(
{
        "schema-version": 1,
        "template": {
        "category-layout": "grid",
        "card-size": "large",
        "overlay": true
        },
        "components": {
        "title": "title",
        "subtitle": "subtitle",
        "art" : {
        "field": "art",
        "aspect-ratio": 2.0
        }
        }
        }
        )";

const std::string CAT_RENDERER11 = R"(
{
        "schema-version" : 1,
        "template" : {
        "category-layout" : "vertical-journal",
        "card-layout": "horizontal",
        "card-size": "small",
        "collapsed-rows": 0
        },
        "components" : {
        "title":"title",
        "subtitle":"subtitle",
        "summary":"summary",
        "art":{
        "field": "art",
        "aspect-ratio": 2
        }
        }
        })";

const static string CAT_RENDERER12
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "vertical-journal",
            "card-layout": "vertical",
            "card-size" : "medium",
            "card-background": "#00FF00"
        },
        "components" :
        {
            "title" : "title",
            "art" : "art",
            "subtitle": "subtitle",
            "mascot": "mascot",
            "emblem": "emblem",
            "summary": "summary",
            "background": "background",
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

const static string CAT_RENDERER13
{
    R"(
    {
        "schema_version" : 1,
        "template" :
        {
            "category-layout" : "horizontal-list",
            "card-layout": "vertical",
            "card-size" : "large",
            "card-background": "#00FF00"
        },
        "components" :
        {
            "title" : "title",
            "art" : "art",
            "subtitle": "subtitle",
            "mascot": "mascot",
            "emblem": "emblem",
            "summary": "summary",
            "background": "background",
            "overlay-color": "overlay-color",
            "attributes": {
                "field": "attributes",
                "max-count": 2
            }
        }
    }
    )"
};

std::string CR_CAROUSEL = R"(
{
        "schema-version" : 1,
        "template" : {
        "category-layout" : "carousel",
        "card-size": "large",
        "overlay" : true
        },
        "components" : {
        "title" : "title",
        "art" : {
        "field": "art",
        "aspect-ratio": 1.6,
        "fill-mode": "fit"
        }
        }
        }
        )";

const static string BUTTONS_TEMPLATE =
        R"(
{
        "schema-version": 1,
        "template": {
        "category-layout": "vertical-journal",
        "card-size": "small",
        "card-background":"color:///#12a3d8"
        },
        "components": {
        "title": "title"
        }
        }
        )";

Query::Query(const sc::CannedQuery &query, const sc::SearchMetadata &metadata,
             QString scopePath, Config::Ptr config) :
    sc::SearchQueryBase(query, metadata), scopePath_(scopePath), client_(config) {

    for ( int i = 0; i < 9; i ++ ) {
        QString name = QString("image").append(QString::number(i+1)).append(".jpg");
        QString image = QString("file://%1/images/%2").arg(scopePath).arg(name);
        images_ << image;
    }

    for ( int i = 0; i < 10; i ++ ) {
        QString name = QString("pic").append(QString::number(i+1)).append(".jpg");
        QString image = QString("file://%1/images/%2").arg(scopePath).arg(name);
        icons_ << image;
    }

    background_ = QString("file://%1/images/%2").arg(scopePath).arg("background.jpg");

}

void Query::cancelled() {
    client_.cancel();
}


void Query::run(sc::SearchReplyProxy const& reply) {
    try {

        // We can play a two buttons on the top
        createButtons(reply);

        // Let's first check the query string
        const sc::CannedQuery &query(sc::SearchQueryBase::query());
        // Get the query string
        string query_string = query.query_string();

        QString queryStr = QString::fromStdString(query_string);
        qDebug() << "query: " << queryStr;

        if ( queryStr.startsWith("carousel") ) {
            qDebug() << "it is from the preview";

            int count = images_.count();
            auto cat = reply->register_category( "Carousel", "Carousel" ,
                                                 "", sc::CategoryRenderer(CAT_RENDERER9) );

            for ( int i = 0; i < count; i ++ ) {
                pushResult( reply, &cat, i);
            }

        } else if (sc::SearchQueryBase::query().has_user_data()) {
            string userdata = sc::SearchQueryBase::query().user_data().get_string();
            qDebug() << "it has user data in it";
            cerr << "user_data: " << userdata << endl;
            const std::string prefix("num=");
            if (!userdata.compare(0, prefix.size(), prefix)) {
                qDebug() << "prefix is found!";
                std::string num = userdata.substr(prefix.size());
                cerr << "num: " << num << endl;
                int number = num.back() - '0';
                qDebug() << "number: " << number;

                // Let's display a vertical-journal according to the number
                auto cat = reply->register_category( "vertical-journal", "vertical-journal" ,
                                                     "", sc::CategoryRenderer(CAT_RENDERER12) );

                for ( int i = 0; i < number; i ++ ) {
                    pushResult( reply, &cat, i);
                }
            }
        }else {
            // The default is vertical
            pushResult(reply, CAT_RENDERER1, 1);
            pushResult(reply, CAT_RENDERER101, 101);
            pushResult(reply, CAT_RENDERER2, 2);
            pushResult(reply, CAT_RENDERER3, 3);
            pushResult(reply, CAT_RENDERER4, 4);
            pushResult(reply, CAT_RENDERER5, 5);
            pushResult(reply, CAT_RENDERER6, 6);
            pushResult(reply, CAT_RENDERER7, 7);
            pushResult(reply, CAT_RENDERER10, 10);
            pushResult(reply, CAT_RENDERER11, 11);

            int count = images_.count();

            auto cat = reply->register_category( "Grid", "Grid" ,
                                                 "", sc::CategoryRenderer(CAT_RENDERER8) );

            for ( int i = 0; i < count/2; i ++ ) {
                pushResult( reply, &cat, i);
            }

            cat = reply->register_category( "Carousel", "Carousel" ,
                                            "", sc::CategoryRenderer(CAT_RENDERER9) );

            for ( int i = 0; i < count; i ++ ) {
                pushResult( reply, &cat, i);
            }

            cat = reply->register_category( "vertical-journal", "vertical-journal" ,
                                            "", sc::CategoryRenderer(CAT_RENDERER12) );

            for ( int i = 0; i < count; i ++ ) {
                pushResult( reply, &cat, i);
            }

            cat = reply->register_category( "horizontal-list", "horizontal-list" ,
                                            "", sc::CategoryRenderer(CAT_RENDERER13) );

            for ( int i = 0; i < count; i ++ ) {
                pushResult( reply, &cat, i);
            }

            cat = reply->register_category( "Linking queries", "Linking queries" ,
                                            "", sc::CategoryRenderer(CAT_RENDERER1) );

            // The link icon's index is 8
            pushResult( reply, &cat, 8, true);

            pushResult(reply, CR_CAROUSEL, 12);
        }

    } catch (domain_error &e) {
        // Handle exceptions being thrown by the client API
        cerr << e.what() << endl;
        reply->error(current_exception());
    }
}

void Query::pushResult(sc::SearchReplyProxy const& reply,
                       const string renderer, int i) {
    stringstream ss;
    ss << i;
    string str = ss.str();

    auto cat = reply->register_category( "id" + str, "Template " + str ,
                                         "", sc::CategoryRenderer(renderer) );
    sc::CategorisedResult r(cat);
    r.set_uri( URI.toStdString() );
    r.set_art( images_[0].toStdString() );
    //    r.set_art("http://api.map.baidu.com/images/weather/night/leizhenyu.png");
    r["subtitle"] = "Subtitle " + str;
    r.set_title("Title " + str);
    r["summary"] = "Summary: " + str;
    r["fulldesc"] = "fulldesc: " + str;
    r["mascot"] = icons_[0].toStdString();
    r["emblem"] = icons_[1].toStdString();
    r["background"] = background_.toStdString();
    r["overlay-color"] = "#FF0000";

    r["comment_icon"] = icons_[3].toStdString();
    r["share_icon"] = icons_[4].toStdString();
    r["share_pic"] = icons_[5].toStdString();

    QString likes = QString("%1 %2").arg(qstr(u8"\u261d "), "100");
    QString views = QString("%1 %2").arg(qstr(u8"   \u261f "), "99");
    std::string both = qstr("%1 %2").arg(likes,views).toStdString();
    sc::VariantBuilder builder;
    builder.add_tuple({
                          {"value", Variant(both)}
                      });
    builder.add_tuple({
                          {"value", Variant("")}
                      });
    r["attributes"] = builder.end();

    r["musicSource"] = "http://qqmp3.djwma.com/mp3/魔音神据极品私货这锯子拉的耳膜都要碎了.mp3";
    r["videoSource"] = "http://techslides.com/demos/sample-videos/small.mp4";
    r["screenshot"] = icons_[2].toStdString();

    // add an array to show the gallary of it
    sc::VariantArray arr;

    for(const auto &datum : icons_) {
        arr.push_back(Variant(datum.toStdString()));
    }

    r["array"] = sc::Variant(arr);

    if (!reply->push(r))
        return;
}

void Query::pushResult(sc::SearchReplyProxy const& reply,
                       const std::shared_ptr<const Category> *cat, int i,
                       bool linkquery) {

    stringstream ss;
    ss << i;
    string str = ss.str();

    sc::CategorisedResult r(*cat);

    // If linkquery is true, we need to redirect it to another scope or
    // a scope department id locally in this scope
    if ( linkquery ) {
        sc::CannedQuery second_query("com.canonical.scopes.news_unity-scope-news");
        second_query.set_department_id("dept-finance");
        r.set_uri(second_query.to_uri());
    } else {
        r.set_uri( URI.toStdString() );
    }

    r.set_art( images_[i].toStdString() );
    r["subtitle"] = "Subtitle " + str;
    r.set_title("Title " + str);
    r["summary"] = "Summary: " + str;
    r["fulldesc"] = "fulldesc: " + str;
    r["mascot"] = icons_[0].toStdString();
    r["emblem"] = icons_[1].toStdString();

    r["comment_icon"] = icons_[3].toStdString();
    r["share_icon"] = icons_[4].toStdString();
    r["share_pic"] = icons_[5].toStdString();
    r["linkquery"] = linkquery;

    QString likes = QString("%1 %2").arg(qstr(u8"\u261d "), "100");
    QString views = QString("%1 %2").arg(qstr(u8"   \u261f "), "99");
    std::string both = qstr("%1 %2").arg(likes,views).toStdString();
    sc::VariantBuilder builder;
    builder.add_tuple({
                          {"value", Variant(both)}
                      });
    builder.add_tuple({
                          {"value", Variant("")}
                      });
    r["attributes"] = builder.end();

    r["musicSource"] = "";
    r["videoSource"] = "";
    r["screenshot"] = "";
    // This is to ensure that the preview can well for the grid/carousel/lists...
    VariantArray arr;
    r["array"] = sc::Variant(arr);;

    if (!reply->push(r))
        return;
}


void Query::showNext(sc::SearchReplyProxy const& reply, sc::CategorisedResult res, int next_breadcrumb)
{
    res.set_uri("http://ubuntu.com");
    //Translators: this means show the next page of results
    std::string show_more =  _("Next");
    res.set_title("<b>" + show_more + "</b>");
    res["get_next"] = "true";
    res.set_intercept_activation();
    res["api_page"] = sc::Variant(next_breadcrumb);
    if (!reply->push(res)) {
        return;
    }
}

void Query::showPrevious(sc::SearchReplyProxy const& reply, sc::CategorisedResult res)
{
    res.set_uri("http://ubuntu.com");
    //Translators: this means show the previous page of results
    std::string show_prev =  _("Previous");
    res.set_title("<b>" + show_prev + "</b>");
    res["get_previous"] = "true";
    res.set_intercept_activation();
    if (!reply->push(res)) {
        return;
    }
}

void Query::showTop(sc::SearchReplyProxy const& reply, sc::CategorisedResult res)
{
    res.set_uri("http://ubuntu.com");
    //Translators: this means return to the top page (the first page) of results
    std::string top = _("Top");
    res.set_title("<b>" + top + "</b>");
    res["go_to_top"] = "true";
    res.set_intercept_activation();
    if (!reply->push(res)) {
        return;
    }
}

void Query::createButtons(const unity::scopes::SearchReplyProxy &reply) {
    auto buttons_cat = reply->register_category("buttons", "", "",
                                                sc::CategoryRenderer(BUTTONS_TEMPLATE));
    // Show the next button
    sc::CategorisedResult res(buttons_cat);
    showNext(reply, res, 1);

    // show the preview button
    sc::CategorisedResult prev_res(buttons_cat);
    showPrevious(reply, prev_res);

    // show the top button
    sc::CategorisedResult top_res(buttons_cat);
    showTop(reply, top_res);
}
