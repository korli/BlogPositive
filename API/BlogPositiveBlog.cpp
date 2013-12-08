/*
*  Copyright 2013 Puck Meerburg, puck@puckipedia.nl
*  All rights reserved. Distributed under the terms of the MIT License.
* /


#include "BlogPositiveBlog.h"

#include <List.h>
#include <String.h>

#include "BlogPositivePlugin.h"

const uint32 kBlogMessage = 'BPBL';

BlogPositiveBlog::BlogPositiveBlog()
{
	fName = new BString();
	fAuthentication = new BString();
}


BList*
BlogPositiveBlog::DeserializeList(BMessage* message, const char* blogName)
{
	BMessage msg;
	BList* Listy = new BList();
	int i = 0;
	while (message->FindMessage(blogName, i++, &msg) == B_OK)
	{
		BlogPositiveBlog* blog = new BlogPositiveBlog();
		blog->Unserialize(&msg);
		Listy->AddItem(blog);
	}
	return Listy;
}


BMessage*
BlogPositiveBlog::SerializeList(BList* blist, const char* blogName)
{
	BMessage* bm = new BMessage();
	for (int i = 0; i < blist->CountItems(); i++)
	{
		bm->AddMessage(blogName,
			((BlogPositiveBlog* )blist->ItemAt(i))->Serialize());

	}
	return bm;
}


void
BlogPositiveBlog::SetName(const char* name)
{
	fName->SetTo(name);
}


const char*
BlogPositiveBlog::Name()
{
	return fName->String();
}


void
BlogPositiveBlog::SetAuthentication(const char* auth)
{
	fAuthentication->SetTo(auth);
}


const char*
BlogPositiveBlog::Authentication()
{
	return fAuthentication->String();
}


void
BlogPositiveBlog::SetBlogHandler(int32 blogHandler)
{
	fBlogHandler = blogHandler;
}


int32
BlogPositiveBlog::BlogHandler()
{
	return fBlogHandler;
}


status_t
BlogPositiveBlog::Archive(BMessage* into, bool deep = true)
{
	into->AddString("name", fName->String());
	into->AddString("auth", fAuthentication->String());
	into->AddInt32("handler", fBlogHandler);
	return B_OK;
}


void
BlogPositiveBlog::Unserialize(BMessage* message)
{
fName->SetTo(message->GetString("name", ""));
fAuthentication->SetTo(message->GetString("auth", ""));
fBlogHandler = message->GetInt32("handler", 0);
}


void
BlogPositiveBlog::SetPlugin(BlogPositivePlugin* plugin)
{
fPlugin = plugin;
}


BlogPositivePlugin*
BlogPositiveBlog::Plugin()
{
return fPlugin;
}


BString*
BlogPositiveBlog::NameString()
{
return fName;
}