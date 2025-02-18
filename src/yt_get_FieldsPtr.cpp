#include "yt_combo.h"
#include "libyt.h"

//-------------------------------------------------------------------------------------------------------
// Function    :  yt_get_FieldsPtr
// Description :  Get pointer of the array of struct yt_field with length num_fields.
//
// Note        :  1. User should call this function after yt_set_Parameters(), since we allocate field_list
//                   there.
//
// Parameter   :  yt_field **field_list  : Initialize and store the field list array under this pointer 
//                                         points to.
//
// Return      :  YT_SUCCESS or YT_FAIL
//-------------------------------------------------------------------------------------------------------
//
int yt_get_FieldsPtr( yt_field **field_list )
{
#ifdef SUPPORT_TIMER
    g_timer->record_time("yt_get_FieldsPtr", 0);
#endif

	// check if libyt has been initialized
   	if ( !g_param_libyt.libyt_initialized ){
    	YT_ABORT( "Please invoke yt_initialize() before calling %s()!\n", __FUNCTION__ );
   	}

	// check if yt_set_Parameters() have been called
   	if ( !g_param_libyt.param_yt_set ) {
    	YT_ABORT( "Please invoke yt_set_Parameters() before calling %s()!\n", __FUNCTION__ );
    }

    // check if num_fields > 0, if not, field_list won't be initialized
    if ( g_param_yt.num_fields <= 0 ){
    	YT_ABORT( "num_fields == %d <= 0, you don't need to input field_list, and it is also not initialized!\n",
    	           g_param_yt.num_fields);
    }

   	log_info( "Getting pointer to field list information ...\n" );

	// Store the field_list ptr to *field_list
	*field_list =  g_param_yt.field_list;

	// Above all works like charm
	g_param_libyt.get_fieldsPtr = true;
	log_info( "Getting pointer to field list information  ... done.\n" );

#ifdef SUPPORT_TIMER
    g_timer->record_time("yt_get_FieldsPtr", 1);
#endif

	return YT_SUCCESS;
}
