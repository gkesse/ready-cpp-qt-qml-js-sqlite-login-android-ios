# Signal

Un **Signal** est une grandeur qui peut varier dans le temps.  

# Programme de Test

**GProcess** est la classe chargée de l'exécution du programme de test.
```
//===============================================
void GProcess::run() {
    GSignal::Instance()->sinus();
    QVector<double> m_x = GSignal::Instance()->getX();
    QVector<double> m_y = GSignal::Instance()->getY();
    double m_xMin = GSignal::Instance()->getXmin();
    double m_xMax = GSignal::Instance()->getXmax();
    double m_yMin = GSignal::Instance()->getYmin();
    double m_yMax = GSignal::Instance()->getYmax();

    GGraphView::Instance()->setColor(QBrush("blue"));
    GGraphView::Instance()->setData(m_x, m_y);
    GGraphView::Instance()->setXRange(m_xMin, m_xMax);
    GGraphView::Instance()->setYRange(m_yMin, m_yMax);
    GGraphView::Instance()->drawGraph();
}
//===============================================
```

**GSignal** est la classe chargée de la génération de signaux. 
`GSignal::Instance()->sinus();`

**GSignal** peut générer plusieurs types de signaux.
```
public:
    void sinus(); //signal sinus
    void cosinus(); // signal cosinus
    void halfwave(); // signal mono-alternance
    void fullwave(); // signal double-alternance
    void square(); // signal carré
    void triangle(); // signal triangle
    void sawtooth(); // signal dent de scie
    void polynomial(); // signal polynôme
```

# Signal Sinus

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/sinus.png)

# Signal Cosinus

![Signal Cosinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/cosinus.png)

# Signal Mono-Alternance

![Signal Mono-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/halfwave.png)

# Signal Double-Alternance

![Signal Double-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/fullwave.png)

# Signal Carré

![Signal Carré](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/square.png)

# Signal Triangle

![Signal Triangle](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/triangle.png)

# Signal Dent de Scie

![Signal Dent de Scie](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/sawtooth.png)

# Signal Polynôme

![Signal Polynôme](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/polynomial.png)

# Voir Aussi

* [ReadyDSP](https://github.com/gkesse/ReadyDSP "ReadyDSP")  
* [Signal](https://github.com/gkesse/ReadyDSP/tree/master/Signal "Signal")  
* [Echantillonnage](https://github.com/gkesse/ReadyDSP/tree/master/Echantillonnage "Echantillonnage")  
* [Transformée de Fourier Rapide](https://github.com/gkesse/ReadyDSP/tree/master/Fourier_FFT "Transformée de Fourier Rapide")  
* [Interpolation](https://github.com/gkesse/ReadyDSP/tree/master/Interpolation "Interpolation")  
* [Intégration](https://github.com/gkesse/ReadyDSP/tree/master/Integration "Intégration")  
