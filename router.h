#pragma once
#include "sne-application-header.h"
#include "template-page.h"
#include "template-page-document.h"


namespace router {
	/*	add pages to app.
		- pages call their settings() attribute upon adding page.
		- if a page is not opened using app.openPage, the first page will be opened by default.
	*/
	void setupRouting() {
		app.title = "myapp";
		app.addPage(templatepage::templatePage.name, &templatepage::templatePage);
	}
}
