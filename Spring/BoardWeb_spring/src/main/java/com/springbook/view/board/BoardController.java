package com.springbook.view.board;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.servlet.ModelAndView;

import com.springbook.biz.board.BoardVO;
import com.springbook.biz.board.impl.BoardDAO;

// BoardController�� ������ ��ɺ��� �ִ� Controller�� �����Ͽ� ������ �� �ִ�.
// ������ Controller���� �����ص� �ȴ�.

// ModelAndView���� String�� ����ϴ� ���� ���� �� �����ϱ� ������ ��κ� String���� ����

@Controller
@SessionAttributes("board")
public class BoardController {
	
	// �˻� ���� ��� ����
	// @ModelAttribute�� LoginController���� �̸� ���� �Ӹ��ƴ϶� View(jsp)���� ����� �����͸� �����ϴ� �뵵�ε� ���ȴ�.
	// @ModelAttribute�� ������ �޼ҵ�� @RequestMapping ������̼��� ����� �޼ҵ庸�� ���� ȣ��ȴ�.
	// @ModelAttribute �޼ҵ� ���� ����� ���ϵ� ��ü�� �ڵ����� Model�� ����ȴ�.
	// @ModelAttribute �޼ҵ��� ���� ����� ���ϵ� ��ü�� View ���������� ����� �� �ִ�.
	@ModelAttribute("conditionMap")
	public Map<String, String> searchConditionMap() {
		Map<String, String> conditionMap = new HashMap<String, String>();
		conditionMap.put("����", "TITLE");
		conditionMap.put("����", "CONTENT");
		return conditionMap;
	}

	// �� ���
	// RequestMapping�� HandlerMapping ������ ��ü�ϱ� ���� ������̼�
	// value ������ Ư���� ��찡 �ƴ϶�� ��κ� �����Ѵ�.

	// Command ��ü�� �̿�, insertBoard() �޼ҵ带 ������ �� ������ �����̳ʰ� Command ��ü�� �����Ͽ� �Ѱ��ְ� ����ڰ�
	// �Է��� ���� ������ Command ��ü�� �����ؼ� �Ѱ��ش�.
	// ��, ��������� ����� �Է� ���� ����� VO ��ü ����, �׸��� �� ������ ��� �����̳ʰ� �ڵ����� ó���ȴ�.
	// �߿��� ���� Form �±׾��� �Ķ���� �Ӹ��� Command ��ü�� Setter �޼ҵ� �̸��� �ݵ�� ��ġ�ؾ� �Ѵ�.
	// ��, �� �Ķ���� �̸��� �ش��ϴ� �޼ҵ尡 �־�� Setter �����ǿ� ���� �ڵ����� ����� �Է°��� ����ȴ�.
	@RequestMapping(value = "/insertBoard.do")
	public String insertBoard(BoardVO vo, BoardDAO boardDAO) {
		System.out.println("�� ��� ó��");

		boardDAO.insertBoard(vo);
		// �������� ���� ��� �� ��� �Ŀ� ��� ȭ���� ������ �������� URL�� ����ȵǴ� ���� �ǹ� (return
		// "getBoardList.do"; -> http://localhost:8090/BoardWeb/insertBoard.do)
		// �����̷�Ʈ�� �� ��� ó�� �Ŀ� �����̷�Ʈ�� �ش�Ǵ� URL�� ���� (return "redirect:getBoardList.do; ->
		// http://localhost:8090/BoardWeb/getBoardList.do)
		return "getBoardList.do";
	}

	// �� ����
	// ����ڰ� �� ȭ���� ��û�ϸ� getBoard() �޼ҵ�� �˻� ����� BoardVO ��ü�� board��� �̸����� Model�� �����Ѵ�.
	// �̶� BoardController Ŭ������ ����� @SessionAttributes("board")������ ���� Model�� "board"��� �̸����� ����Ǵ� �����Ͱ� �ִٸ�
	// �� �����͸� ����(HttpSession)���� �ڵ����� �����϶�� �����̴�.
	// ���� getBoard() �޼ҵ尡 ����Ǿ� �� ȭ���� ��µǸ� ���������� Model�� board��� �̸����� BoardVO ��ü�� ����ǰ� 
	// ���ǿ��� board��� �̸����� BoardVO ��ü�� ����ȴ�.
	
	// ����ڰ� �� ���� ��ư�� Ŭ���ϸ�, updateBoard() �޼ҵ尡 ����ǰ� �̶� ������ �����̳ʴ� �켱 @ModelAttribute("board") ������ �ؼ��Ͽ�
	// ���ǿ� board��� �̸����� ����� �����Ͱ� �ִ����� Ȯ���Ѵ�.
	// �׸��� �ִٸ� �ش� ��ü�� ���ǿ��� ������ �Ű������� ����� vo ������ �Ҵ��Ѵ�.
	// �̶� ����ڰ� �Է��� ���� �������� ���Ӱ� �Ҵ�ȴ�.
	@RequestMapping("/updateBoard.do")
	public String updateBoard(@ModelAttribute("board") BoardVO vo, BoardDAO boardDAO) {
		System.out.println("�� ���� ó��");

		System.out.println("��ȣ : " + vo.getSeq());
		System.out.println("���� :" + vo.getTitle());
		System.out.println("�ۼ��� : " + vo.getWriter());
		System.out.println("���� : " + vo.getContent());
		System.out.println("����� : " + vo.getRegDate());
		System.out.println("��ȸ�� : " + vo.getCnt());

		boardDAO.updateBoard(vo);
		return "getBoardList.do";
	}

	// �� ����
	@RequestMapping("/deleteBoard.do")
	public String deleteBoard(BoardVO vo, BoardDAO boardDAO) {
		System.out.println("�� ���� ó��");

		boardDAO.deleteBoard(vo);
		return "getBoardList.do";
	}

	// ModelAndView
	/*
	// �� �� ��ȸ
	@RequestMapping("/getBoard.do") public ModelAndView getBoard(BoardVO vo, BoardDAO boardDAO, ModelAndView mav) { 
		System.out.println("�� �� ��ȸ ó��");

		// 3. �˻� ����� ȭ�� ������ ModelAndView�� �����Ͽ� �����Ѵ�. mav.addObject("board",
		boardDAO.getBoard(vo)); // Model ���� ����
		mav.setViewName("getBoard.jsp"); // View ���� ���� 
		return mav; 
	}
		
	// �� ��� �˻� 
	@RequestMapping("/getBoardList.do") public ModelAndView getBoardList(BoardVO vo, BoardDAO boardDAO, ModelAndView mav) { 
		System.out.println("�� ��� �˻� ó��");
	
		// 3. �˻� ����� ȭ�� ������ ModelAndView�� �����Ͽ� �����ϴ�. 
		mav.addObject("boardList", boardDAO.getBoardList(vo)); // Model ���� ����
		mav.setViewName("getBoardList.jsp"); // View ���� ���� 
		return mav; 
	}
	*/

	// String
	// �� �� ��ȸ
	@RequestMapping("/getBoard.do")
	public String getBoard(BoardVO vo, BoardDAO boardDAO, Model model) {
		System.out.println("�� �� ��ȸ ó��");

		model.addAttribute("board", boardDAO.getBoard(vo)); // Model ���� ����
		return "getBoard.jsp"; // View �̸� ����
	}

	// �� ��� �˻�
	
	// @RequestParam�� ����ϸ� Command ��ü���� ���� �Ķ���͸� Controller Ŭ�������� ����� �����ϴ�.
	// HttpServltRequest���� �����ϴ� getParameter() �޼ҵ�� ���� ����� ������̼��̴�.
	// �Ӽ��� �ǹ̴�
	// value : ȭ�����κ��� ���޵� �Ķ���� �̸�
	// defaultValue : ȭ�����κ��� ���޵� �Ķ������ ������ ���� ��, ������ �⺻��
	// required : �Ķ������ ���� ����
	// ���� @RequestParam�� ����ϱ� �ȴٸ� BoardVO Ŭ������ searchCondition, searchKeyword ������ �߰��ϰ� Getter/Setter �޼ҵ常 �߰��ϸ� �ȴ�.
	@RequestMapping("/getBoardList.do")
	public String getBoardList(@RequestParam(value="searchCondition", defaultValue="TITLE", required=false) String condition,
			                   @RequestParam(value="searchKeyword", defaultValue="", required=false) String keyword, 
			                   BoardVO vo, BoardDAO boardDAO, Model model) {
		System.out.println("�� ��� �˻� ó��");
		
		System.out.println("�˻� ���� : " + condition);
		System.out.println("�˻� �ܾ� : " + keyword);

		// Model ���� ����
		model.addAttribute("boardList", boardDAO.getBoardList(vo));
		return "getBoardList.jsp";
	}

}
