# pyRedshift
Redshift renderer SDK python bind

Notice: Currently the CMakeLists is written for windows , if you want to compile in linux, you must change the CMakeLists



before compile pyRedshift you must do some things

## 1. Comment the method

	template < typename ParamType >
	inline unsigned int		SetParameterData( const char* paramName, const ParamType data )									
    { return SetParameterData( GetParameterIndex(paramName), data ); }

in redshift sdk, RS_ShaderNode.h

## 2. Add method 

    bool operator==(const RSUInt2& p) const { return ((p.x == x) && (p.y == y)); }

to redshift sdk, RS_Datatypes.h, struct RSUInt2