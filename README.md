# img_plotter

<img src="https://github.com/bvaleria02/img_plotter/blob/main/result.png?raw=true" />
<p> This is the output when you run the program by default </p>

Simple line and rectangle drawing tool made in C

<h2> Definitions </h2>

<h3>byte:</h3>
<h4><i>unsigned char</i></h4>
<br>
<h3>IMG:</h3>
<h4><i>struct:</i></h4>
<p><kbd>  - width  </kbd>: width of the image</p>
<p><kbd>  - length </kbd>: height of the image</p>
<p><kbd>  - name   </kbd>: name of the output file</p>
<p><kbd>  - raw    </kbd>: raw data array</p>
<br>
<h3>COLOR:</h3>
<h4><i>struct:</i></h4>
<p><kbd>  - r </kbd>: $`\textcolor{red}{\text{Red}}`$ channel value</p>
<p><kbd>  - g </kbd>: $`\textcolor{green}{\text{Green}}`$ channel value</p>
<p><kbd>  - b </kbd>: $`\textcolor{blue}{\text{Blue}}`$ channel value</p>
<p><kbd>  - a </kbd>: $`\textcolor{gray}{\text{Aplha}}`$ channel value</p>
<br>
<br>
<h2>Functions</h2>
<br>
<b>generateBlank:</b>
<kbd>(struct IMG *image, struct COLOR *col)</kbd>
<p>Creates an array with the defined color as base</p>
<br>
<b>colorSet:</b>
<kbd>(struct COLOR *col, int r, int g, int b, int a)</kbd>
<p>Writes into the struct the rbga values</p>
<br>
<b>imageWrte:</b>
<kbd>(struct IMG *image)</kbd>
<p>Writes a file the data from the generated image</p>
<br>
<b>subSampler:</b>
<kbd>(struct IMG *image, int s)</kbd>
<p>Generates an image smaller than the original. Argument <kbd>s</kbd> can be set to define the final size in powers of two</p>
<p> 0 = original size</p>
<p> 1 = halve all dimensions (image gets quarter the size)</p>
<p> 2 = every dimension is aquarter from the original (iimage is now 1/16th of the original size)</p>
<p> n = width/2^n, height/2^n, image gets 1/2^(2n) the size.
<br>
<br>
<h2>Draw functions</h2>
<br>
<h3>image_drawLine:</h3>
<kbd>(struct IMG *image, struct COLOR *col, int x1, int y1, int x2, int y2)</kbd>
<p>Draw a line between (x1,y1) to (x2,y2), with the desired color passed by <kbd>col</kbd></p>
<br>
<h3>image_drawRect:</h3>
<kbd>(struct IMG *image, struct COLOR *col, int x1, int y1, int x2, int y2)</kbd>
<p>Draw a solid rectangle from (x1,y1) to (x2,y2), with the desired color passed by <kbd>col</kbd></p>
