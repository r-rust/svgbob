# SvgBob in R

[![Build Status](https://travis-ci.org/r-rust/svgbob.svg)](https://travis-ci.org/r-rust/svgbob)
[![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/github/r-rust/svgbob)](https://ci.appveyor.com/project/jeroen/svgbob)

> Svgbob is a diagramming model which uses a set of typing characters
  to approximate the intended shape. It allows for converting ascii art into
  beautiful svg images.
  
This R package wraps the [svgbob](https://crates.io/crates/svgbob) cargo crate.
  
## Examples

Input text:

```
    E +-------------------------*--+     E |                         o    
    D |-------------------*--*--|--*     D |                   o  o  |  o 
    C |-------------*--*  |  |  |  |     C |             o  o  |  |  |  | 
    B |-------*--*  |  |  |  |  |  |     B |       o  o  |  |  |  |  |  | 
    A +-*--*--+--+--+--+--+--+--+--+     A +-o--o--|--|--|--|--|--|--|--| 
        5 10 15 20 25 30 35 40 45 50         5 10 15 20 25 30 35 40 45 50 
```

```r
text <- readLines(system.file('examples/demo.bob', package = 'svgbob'))
svgbob(text[66:72], 'chart.svg')
```

![chart_svg](chart.svg)

Suppose input text looks like this:

```

     +10-15V           ___0,047R
    +--------o------o-|___|-o--o---------o----o-------o
  + |        |      |       |  |         |    |       |
  -===-     _|_     |       | .+.        |    |       |
  -===-     .-.     |       | | | 2k2    |    |       |
  -===-   470| +    |       | | |        |    |       |
  - |      uF|      '--.    | '+'       .+.   |       |
    +--------o         |6   |7 |8    1k | |   |       |
          ___|___    .-+----+--+--.     | |   |       |
           -═══-     |            |     '+'   |       |
             -       |            |1     |  |/  BC    |
            GND      |            |------o--+   547   |
                     |            |      |  |`>       |
                     |            |     .+.   |       |
                     |            | 220R| |   o----||-+  IRF9Z34
                     |            |     | |   |    |+->
                     |  MC34063   |     '+'   |    ||-+
                     |            |      |    |       |  BYV29     -12V6
                     |            |2     '----'       o--|<-o----o--X OUT
                     |            +--+                |     |    |
                     |            |  |                C|    |    |
                     |            |  |          30uH  C|    |   _|_ 470
                     |            |3 |    1nF         C|    |   .-.  uF
                     |            |--)----|(--.       |     |    | +
                     '-----+----+-'  |        |      GND    |    |
                          5|   4|    |        |             |    |
                           |    |___.-._______|_____________|    |
                           |         |                 ___  |    |
                           +---------(-------------o--|___|-+    |
                                     |             |       1k0   |
                                     +-----+      .+.            |
                                           |      | | 5k6 + 3k3  |
                                           |      | | in Serie   |
                                           |      '+'            |
                                           |       |             |
                                           +-------*-------------'
                                                ___|___ 
                                                 -═══- 
                                                   - 
                                                  GND 
```

Convert to svg or png:

```r
text <- readLines(system.file('examples/circuits.bob', package = 'svgbob'))
svgbob(text[1:41], 'circuits.svg')
```

![output_svg](circuits.svg)

## SpongeDown

   Q: "How to integrate this in markdown?"
   A: "There is a project called [Spongedown](https://ivanceras.github.io/spongedown)"
      which specifically does that. The svgbob diagramming feature is guarded
      with ```bob code block so as not to pollute the markdown syntax.

## Installation in R

The [hellorust readme](https://github.com/r-rust/hellorust#installation) has instructions on how to setup rust on Windows, MacOS or Linux. After that you can just do:

```r
devtools::install_github("r-rust/svgbob")
```
