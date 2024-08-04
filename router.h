#pragma once
#include "sne-application-header.h"
#include "template-page.h"
#include "template-page2.h"


namespace router {
	// Add pages to app instance here. If a page is not opened using app.openPage, the first page will be opened by default.
	void setupPaging() {
		app.title = "myapp";
		app.addPage(templatePage.name, &templatePage);
		app.addPage(templatePage2.name, &templatePage2);
	}
}
