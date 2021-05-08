<?php
require_once '../ex00/Color.class.php';
class Vertex
{
	public static $verbose = False;
	private $_x;
	private $_y;
	private $_z;
	private $_w;
	private $_color;
	static function doc()
	{
		return (file_get_contents('Vertex.doc.txt'));
	}
	public function __construct(array $kwargs)
	{
		$this->_x = $kwargs['x'];
		$this->_y = $kwargs['y'];
		$this->_z = $kwargs['z'];
		$this->_color = new Color(array('red'=>255, 'green'=>255, 'blue'=>255));
		if (array_key_exists('w', $kwargs))
			$this->_w = $kwargs['w'];
		else
			$this->_w = 1.0;
		if (array_key_exists('color', $kwargs))
		{
			$this->_color->red = $kwargs['color']->red;
			$this->_color->green = $kwargs['color']->green;
			$this->_color->blue = $kwargs['color']->blue;
		}
		if (self::$verbose == True)
			print('Vertex( x: ' . sprintf("%.2f", $this->_x) . ', y: '
			. sprintf("%.2f", $this->_y) . ', z:' . sprintf("%.2f", $this->_z) .
			', w:' . sprintf("%.2f", $this->_w) . ', ' . $this->_color .
			' ) constructed' . PHP_EOL);
	}
	public function getVertex()
	{
		return(array('x'=>$this->_x, 'y'=>$this->_y, 'z'=>$this->_z,
			'w'=>$this->_w, 'color'=>$this->_color));
	}
	public function setVertex(array $kwargs)
	{
		if (array_key_exists('x', $kwargs))
			$this->_x = $kwargs['x'];
		if (array_key_exists('y', $kwargs))
			$this->_y = $kwargs['y'];
		if (array_key_exists('z', $kwargs))
			$this->_z = $kwargs['z'];
		if (array_key_exists('w', $kwargs))
			$this->_w = $kwargs['w'];
		if (array_key_exists('color', $kwargs))
			$this->_color = clone $kwargs['color'];
	}
	public function __tostring()
	{
		if (self::$verbose == True)
			return('Vertex( x: ' . sprintf("%.2f", $this->_x) . ', y: '
			. sprintf("%.2f", $this->_y) . ', z:' . sprintf("%.2f", $this->_z) .
			', w:' . sprintf("%.2f", $this->_w) . ', ' . $this->_color .
			' )');
		else
			return('Vertex( x: ' . sprintf("%.2f", $this->_x) . ', y: '
			. sprintf("%.2f", $this->_y) . ', z:' . sprintf("%.2f", $this->_z) .
			', w:' . sprintf("%.2f", $this->_w) . ')');
	}
	public function __destruct()
	{
		if (self::$verbose == True)
			print('Vertex( x: ' . sprintf("%.2f", $this->_x) . ', y: '
			. sprintf("%.2f", $this->_y) . ', z:' . sprintf("%.2f", $this->_z) .
			', w:' . sprintf("%.2f", $this->_w) . ', ' . $this->_color .
			' ) destructed' . PHP_EOL);
	}
}
?>
