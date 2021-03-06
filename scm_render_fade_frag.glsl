#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect color0;
uniform sampler2DRect color1;

uniform float t;

void main()
{
	gl_FragColor = mix(texture2DRect(color0, gl_TexCoord[0].xy),
					   texture2DRect(color1, gl_TexCoord[0].xy), t);
}
