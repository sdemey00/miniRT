% ---------------------------------------------------------------------------- %
% ft-latex/ft-beamer.cls                                                       %
%                                                                              %
% MICHELETTI Matteo (https://github.com/TotemaM)                               %
%                                                                              %
% This file is under MIT Licence                                               %
% ---------------------------------------------------------------------------- %

\ProvidesClass{ft-beamer}[]

\LoadClass{beamer}

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{beamer}}
\ProcessOptions\relax

\usepackage{ft-beamer}

% Remove navigation symbols at the bottom.
\setbeamertemplate{navigation symbols}{}

% Changing colors of some elements of the slideshow.
\setbeamercolor{title}{fg=black}
\setbeamercolor{frametitle}{fg=black}
\setbeamercolor{section in toc}{fg=black}
\setbeamertemplate{section in toc}{--~\inserttocsection\par}
\setbeamertemplate{subsection in toc}{\hspace*{10px}--~\inserttocsubsection\par}

\usebackgroundtemplate {
	\includegraphics[width=\paperwidth, height=\paperheight] {
		beamer_background.png
	}
}
