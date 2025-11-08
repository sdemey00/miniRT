% ---------------------------------------------------------------------------- %
% ft-latex/ft-aricle.cls                                                       %
%                                                                              %
% MICHELETTI Matteo (https://github.com/TotemaM)                               %
%                                                                              %
% This file is under MIT Licence                                               %
% ---------------------------------------------------------------------------- %

\ProvidesClass{ft-article}[]

\LoadClass[12pt]{article}

\usepackage[a4paper, top=2cm, bottom=2cm, left=2cm, right=2cm]{geometry}

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{article}}
\ProcessOptions\relax

\setlength{\parindent}{0pt}

\usepackage{ft-article}

\usepackage{background}
\backgroundsetup{
	scale=1,
	angle=0,
	opacity=1,
	contents={
		\includegraphics[width=\paperwidth,height=\paperheight]{
			article_background.png
		}
	}
}

\usepackage{hyperref}