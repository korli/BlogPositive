/*
 * Copyright 2013 Puck Meerburg, puck@puckipedia.nl
 * All rights reserved. Distributed under the terms of the MIT License.
 */
#ifndef BP_OS_PLUGIN_H
#define BP_OS_PLUGIN_H


#include "BlogPositiveBlogPlugin.h"
#include "BlogPositivePost.h"

class BlogPositiveBlog;
class BString;
class XmlNode;

class OnSugarPlugin : public BlogPositiveBlogPlugin
{
public:
	uint32				Version();
	const char*			Name();
	
	uint32				MainHandler();
	bool				Supports(uint32 Code);
	
	void				GetAuthentication(BString auth, BString* Username,
							BString* Password, BString* BlogUrl);
	XmlNode*			Get(BString* responseString, BString apiEndpoint,
							BString auth);
	XmlNode*			Post(BString* responseString, BString apiEndpoint,
							BString requestString, BString auth);

	PostList*			GetBlogPosts(BlogPositiveBlog* blog);
	void				SavePost(BlogPositivePost* post);
	BlogPositivePost*	CreateNewPost(BlogPositiveBlog* blog,
							const char* name);
	void				RemovePost(BlogPositivePost* aPost);
	void				OpenNewBlogWindow(BlogPositiveBlogListDelegate* dele);
};

#endif
