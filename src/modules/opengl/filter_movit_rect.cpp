/*
 * filter_movit_rect.cpp
 * Copyright (C) 2013 Dan Dennedy <dan@dennedy.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <framework/mlt.h>
#include "glsl_manager.h"

static mlt_frame process( mlt_filter filter, mlt_frame frame )
{
	// Drive the resize and resample filters on the b_frame for these composite parameters
	mlt_properties properties = MLT_FILTER_PROPERTIES(filter);
	mlt_properties frame_props = MLT_FRAME_PROPERTIES(frame);
	mlt_properties_set( frame_props, "resize.rect", mlt_properties_get( properties, "rect" ) );
	mlt_properties_set( frame_props, "resize.fill", mlt_properties_get( properties, "fill" ) );
	mlt_properties_set( frame_props, "resize.halign", mlt_properties_get( properties, "halign" ) );
	mlt_properties_set( frame_props, "resize.valign", mlt_properties_get( properties, "valign" ) );
	return frame;
}

extern "C"
mlt_filter filter_movit_rect_init( mlt_profile profile, mlt_service_type type, const char *id, char *arg )
{
	mlt_filter filter = NULL;
	GlslManager* glsl = GlslManager::get_instance();

	if ( glsl && ( filter = mlt_filter_new() ) ) {
		mlt_properties_set( MLT_FILTER_PROPERTIES(filter), "rect", arg );
		mlt_properties_set_int( MLT_FILTER_PROPERTIES(filter), "fill", 1 );
		filter->process = process;
	}
	return filter;
}
